#include <iostream>
#include <vector>
#define MAX 20000000
#define fori(n) for(int i = 0; i < n; i++)

using namespace std;

vector<int> primes;
bool isprime[MAX];

int trans[] = {127 - 8, 36, 127 - 2 - 32, 
               127 - 2 - 16, 46, 127 - 4 - 16, 127 - 4, 
               39, 127, 127 - 16};

/*
    -   1
   | | 2 4
    -   8
   | | 1632
    _   64
*/

int drs(int n) {
    int t = 0;
    while(n > 0) {
        t += n%10;
        n /= 10;
    }
    return t;
}

int naive(int n) {
    int t = 0;
    while (n > 0) {
        t += __builtin_popcount(trans[n%10]);
        n /= 10;
    }
    return t;
}

int smart(int a, int b) {
    if (a > b) {
        cout << "Error! Not in order!" << endl;
        return -1;
    }
    int t = 0;
    while(a > 0) {
        int common = (trans[a%10])&(trans[b%10]);
        t += __builtin_popcount(trans[a%10] - common);
        t += __builtin_popcount(trans[b%10] - common);
        a/=10;
        b/=10;
    }
    t += naive(b);
    return t;
}

long long transitions(int a, int b) {
    int samc = naive(a) + naive(b);
    int maxc = smart(a, b);
    /*cout << b << " -> " << a << ": ";
    cout << "Sam " << naive(a) << " - " << naive(b) << endl; 
    cout << "Max " << maxc << endl;*/
    return samc - maxc;
}

int main() {
    fori(MAX) isprime[i] = true;
    int startindex = 0;
    for(int i = 2; i < MAX; i++) {
        if (isprime[i]) {
            if (startindex == 0 && i > MAX/2) startindex = primes.size();
            primes.push_back(i);
            for(int j = 2*i; j < MAX; j += i) isprime[j] = false;
        }
    }
    cout << "Done generating " << primes.size() << " primes" << endl;
    long long nt = 0;
    for(int i = startindex; i < primes.size(); i++) {
    //int k = 137;
        int k = primes[i];
        while(k > 9) {
            int prev = k;
            k = drs(k);
            nt += transitions(k, prev);
        }
    }
    cout << nt << endl;
    cin.get();
    return 0;
}
