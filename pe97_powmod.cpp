#include <iostream>

using namespace std;

long long timesmod(long long a, long long b, long long m) {
    long long res = 0;
    long long p = a;
    while (b > 0) {
        if (b&1LL) {
            res = (p+res) % m;
        }
        p = (p+p) % m;
        b >>= 1;
    }
    return res;
}

long long powmod(long long a, long long b, long long m) {
    long long res = 1;
    long long p = a;
    while (b > 0) {
        if (b&1LL) {
            res = timesmod(p, res, m);
        }
        p = timesmod(p, p, m);
        b >>= 1;
    }
    return res;
}

int main() {
    cout << 28433*powmod(2, 7830457, 10000000000LL) + 1 << endl;
    cin.get();
    return 0;
}
