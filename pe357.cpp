#include <iostream>
#define N 100000000

using namespace std;

unsigned long long primes[N/10];
bool isprime[N];
int nprimes = 0;

int main() {
    // generate primes
    for (int i = 0; i < N; ++i) isprime[i] = true;
    for (int i = 2; i < N/2; ++i) {
        if (!isprime[i]) continue;
        primes[nprimes++] = i;
        for (int j = 2*i; j < N; j += i) isprime[j] = false;
    }

    unsigned long long ans = 1; // Special cases: n = 1
    int nc = 0;
    for (int i = 0; i < nprimes; ++i) {
        if (isprime[2*primes[i] - 3]) {
            unsigned long long n = 2*primes[i] - 4;
            bool works = true;
            for (int j = 1; j*j < n; ++j) {
                if (!(n%j) && !isprime[j + n/j]) {
                    works = false;
                    break;
                }
            }
            if (works){
                ans += n;
            }
            ++nc;
            if (nc%1000 == 0) cout << nc << endl;
        }
    }
    cout << ans << endl;
    return 0;
}

