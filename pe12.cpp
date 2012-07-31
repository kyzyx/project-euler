#include <iostream>
#include <vector>
#define MAX 10000

using namespace std;

int isprime[MAX];
vector<int> primes;

int main() {
    for(int i = 0; i < MAX; ++i) isprime[i] = -1;
    for(int i = 2; i < MAX; ++i) {
        if (isprime[i] == -1) {
            primes.push_back(i);
            for(int j = i; j < MAX; j += i) isprime[j] = i;
        }
    }
    
    int tri = 0;
    for(int i = 1; i < MAX*MAX; ++i) {
        tri += i;
        int tot = 1;
        int n = tri;
        for(int j = 0; primes[j] <= n && j < primes.size(); ++j) {
            int ct = 1;
            while(n%primes[j] == 0) {
                ++ct; n /= primes[j];
            }
            tot *= ct;
        }
        if (tot > 500) {
            cout << tri << endl;
            break;
        }
    }
    
    cin.get();
    return 0;
}
