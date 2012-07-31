#include <iostream>
#define M 100000000

using namespace std;

int primes[M/6];
bool isprime[M];
int np = 0;

long long divmod(int a, int d, int p) {
    // solves ax - qp = 1
    long long x = 0; long long lx = 1;
    long long b = p;
    long long q,r,t;
    while (b != 0) {
        q = a/b;
        r = a%b;
        a = b;
        b = r;
        t = x;
        x = lx - q*x; lx = t;
    }
    while (lx < 0) lx += p;
    lx *= d;
    lx %= p;
    return lx;
}

long long f(int p) {
    // (p-1)! = p-1 (mod p), (p-2)! = 1 (mod p)
    long long result = 1;
    long long tot = 0;
    for (int m = 2; m < 5; ++m) {
       result = divmod((p-m)?(p-m):1, result, p);
       tot += result;
    }
    return tot%p;
}

int main() {
    long long tot = 0;

    for (int i = 0; i < M; ++i) {
        isprime[i] = true;
    }
    for (int i = 2; i < M; ++i) {
        if (isprime[i]) {
            primes[np++] = i;
            for (int j = 2*i; j < M; j += i) {
                isprime[j] = false;
            }
        }
    }
    cout << "Done generating primes" << endl;
    for (int i = 0; i < np; ++i) {
        if (primes[i] < 5) continue;
        tot += f(primes[i]);
    }

    cout << tot << endl;
    return 0;
}
