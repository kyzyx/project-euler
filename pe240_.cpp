#include <iostream>
#define D 12
#define N 20
#define T 10
#define S 70

using namespace std;

int value(unsigned int n) {
    int t = 0;
    int b = 0;
    for (int v = D; v > 1; --v) {
        int c = 0;
        while (n && !(n&1)) {
            ++c;
            n >>= 1;
        }
        if (b+c > T) {
            return t + v*(T-b) == S;
        }
        b += c;
        t += c*v;
        if (t > S) return false;
        n >>= 1;
    }
    return t + (T-b) == S;
}

unsigned long long facs[21];
unsigned long long perms(unsigned int n) {
    unsigned long long ret = facs[20];
    int b = 0;
    while (n) {
        int c = 0;
        while (n && !(n&1)) {
            ++c;
            n >>= 1;
        }
        b += c;
        ret /= facs[c];
        n >>= 1;
    }
    ret /= facs[N-b];
    return ret;
}

int main() {
    unsigned long long ans = 0;
    unsigned long long lim = 1ULL << (D+N-1);
    facs[0] = 1;
    for (int i = 1; i < 21; ++i) {
        facs[i] = facs[i-1]*i;
    }
    for (unsigned long long i = 2047; i < lim; ++i) {
        if (__builtin_popcount(i) != D-1) continue;
        if (value(i)) {
            ans += perms(i);
        }
    }
    cout << ans << endl;
    return 0;
}
