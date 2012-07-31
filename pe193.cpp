#include <iostream>

unsigned long long M = 1ULL << 50;
unsigned long long N = 1ULL << 25;

using namespace std;

unsigned long long* primes;
bool* isprime;
int nprimes = 0;

unsigned long long pierec(int ind, int n, unsigned long long prod, int d) {
    if (d == n) return M/prod;
    unsigned long long tot = 0;
    for (int i = ind+1; i < nprimes; ++i) {
        if (primes[i] > M/prod + 1) break;
        tot += pierec(i, n, prod*primes[i], d+1);
    }
    return tot;
}

unsigned long long pie(int n) {
    unsigned long long tot = 0;
    for (int i = 0; i < nprimes; ++i) {
        tot += pierec(i, n, primes[i], 1);
    }
    return tot;
}

int main() {
    primes = new unsigned long long[N/10];
    isprime = new bool[N];
    // generate primes
    for (int i = 0; i < N; ++i) isprime[i] = true;
    for (int i = 2; i < N; ++i) {
        if (!isprime[i]) continue;
        primes[nprimes++] = ((unsigned long long) i) * i;
        for (int j = 2*i; j < N; j += i) isprime[j] = false;
    }

    unsigned long long ans = 0;
    // PIE 1
/*    for (int i = 0; i < nprimes; ++i) {
        ans += M/primes[i];
    }
    cout << ans << ": " << pie(1) << endl;
    // PIE 2
    for (int i = 0; i < nprimes; ++i) {
        for (int j = i+1; j < nprimes; ++j) {
            if (primes[j]*primes[i] > M) break;
            a2 += M/(primes[i]*primes[j]);
        }
    }
    cout << a2 << ": " << pie(2) << endl;*/
    for (int i = 1; i < 11; ++i) {
        ans += ((i&1)?1:-1) * pie(i);
        cout << i << endl;
    }
    delete [] primes;
    delete [] isprime;
    cout << M-ans << endl;
    return 0;
}

