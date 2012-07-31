#include <iostream>
#define N 10000000

using namespace std;

unsigned long long pows[N/10][24];
unsigned long long primes[N/10];
bool isprime[N];
int nprimes = 0;

unsigned long long q(int a, int b) {
    unsigned long long best = 0;
    for (int i = 0; i < 24 && pows[a][i] != 0; ++i) {
        for (int j = 0; j < 24 && pows[b][j] != 0; ++j) {
            unsigned long long curr = pows[a][i]*pows[b][j];
            if (curr > N) break;
            if (curr > best) best = curr;
        }
    }
    return best;
}

int main() {
    // generate primes
    for (int i = 0; i < N; ++i) isprime[i] = true;
    for (int i = 2; i < N/2; ++i) {
        if (!isprime[i]) continue;
        primes[nprimes++] = i;
        for (int j = 2*i; j < N; j += i) isprime[j] = false;
    }
    for (int i = 0; i < nprimes; ++i) {
        pows[i][0] = primes[i];
        for (int j = 1; j < 24; ++j) {
            if (pows[i][j-1] < N) pows[i][j] = primes[i]*pows[i][j-1];
            else pows[i][j] = 0;
        }
    }

    unsigned long long ans = 0;
    for (int i = 0; i < nprimes; ++i) {
        for (int j = i+1; j < nprimes && primes[i]*primes[j] < N; ++j) {
            ans += q(i,j);
        }
    }
    cout << ans << endl;
    return 0;
}

