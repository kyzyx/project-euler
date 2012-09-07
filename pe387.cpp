#include <iostream>
#define M 10000000
#define D 14

using namespace std;

int primes[M/2];
bool isprime[M];
int np = 0;

long long tot = 0;

bool isPrime(long long n) {
    if (n < M) return isprime[n];
    for (int i = 0; i < np && primes[i]*primes[i] < n; ++i) {
        if (n%primes[i] == 0) return false;
    }
    return true;
}

void genHarshad(long long n, long long sd, int d) {
    // n is a harshad number.
    bool strong = isPrime(n/sd);
    if (d == D) return;
    for (int i = 0; i < 10; ++i) {
        if (strong && isPrime(10*n+i)) tot += 10*n+i;
        if ((10*n + i) % (sd + i) == 0) genHarshad(10*n+i, sd+i, d+1);
    }
}

int main() {
    for (int i = 0; i < M; ++i) isprime[i] = true;
    for (int i = 2; i < M; ++i) {
        if (isprime[i]) {
            primes[np++] = i;
            for (int j = 2*i; j < M; j += i) isprime[j] = false;
        }
    }


    for (int i = 10; i < 100; ++i) {
        if (i % (i/10 + i%10) == 0) genHarshad(i, i/10 + i%10, 2);
    }
    cout << tot << endl;
    return 0;
}
