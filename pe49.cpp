#include <iostream>
#include <vector>

using namespace std;

bool isprime[10000];
vector<int> primes;

bool perms(int a, int b) {
    int used[10];
    for(int i = 0; i < 10; ++i) used[i] = 0;
    while(a>0) {
        ++used[a%10]; --used[b%10];
        a /= 10; b /=10;
    }
    for(int i = 0; i < 10; ++i) if (used[i]) return false;
    return true;
}

int main() {
    for(int i = 0; i < 10000; ++i) isprime[i] = true;
    for(int i = 2; i < 10000; ++i) {
        if (isprime[i]) {
            if (i > 1000) primes.push_back(i);
            for(int j = 2*i; j < 10000; j += i) isprime[j] = false;
        }
    }
    
    for(int i = 0; i < primes.size(); ++i) {
        for(int j = i+1; j < primes.size(); ++j) {
            if (2*primes[j] - primes[i] < 10000 && isprime[2*primes[j] - primes[i]]) {
                if (perms(primes[i], primes[j]) && perms(primes[i], 2*primes[j] - primes[i])) {
                    cout << primes[i] << primes[j] << 2*primes[j] - primes[i] << endl;
                    break;
                }
            } 
        }
    }
    cin.get();
    return 0;
}
