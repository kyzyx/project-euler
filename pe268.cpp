#include <iostream>
#define M 30
#define K 4

using namespace std;

long long MAX = 10000000000000000LL;
long long primes[M];
long long counts[M];
int np = 0;

long long ncr(long long n, long long r) {
    if (r > n/2) r = n-r;
    long long ret = 1;
    for (int i = 0; i < r; ++i) {
        ret *= n - i;
    }
    for (int i = 2; i <= r; ++i) {
        ret /= i;
    }
    return ret;
}

long long set(int n) {
    long long ret = 1;
    for (int i = 0; n; ++i) {
        if (n&1) {
            ret *= primes[i];
            if (ret > MAX) return -1;
        }
        n >>= 1;
    }
    return ret;
}

int main() {
    bool isprime[100];
    for (int i = 0; i < 100; ++i) isprime[i] = true;
    for (int i = 2; i < 100; ++i) {
        if (isprime[i]) {
            primes[np++] = i;
            for (int j = 2*i; j < 100; j += i) isprime[j] = false;
        }
    }

    for (int i = 0; i <= np; ++i) {
        if (i < K) counts[i] = 0;
        else if (i == K) counts[i] = 1;
        else {
            long long tmp = 0;
            for (int j = K; j < i; ++j) {  // how many times are we counting?
                tmp += ncr(i,j)*counts[j];
            }
            counts[i] = 1 - tmp;
        }
    }

    long long cnt = 0;
    for (int i = 0; i < (1<<np); ++i) {
        if (__builtin_popcount(i) < K || __builtin_popcount(i) > 16) continue;
        long long ss = set(i);
        if (ss > MAX || ss == -1) continue;
        cnt += counts[__builtin_popcount(i)]*(MAX/set(i));
    }
    cout << cnt << endl;
}
