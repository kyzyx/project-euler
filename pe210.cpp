#include <iostream>
#include <cmath>

long long R = 1000000000LL;

using namespace std;

long long isqrt(long long a) {
    long long op = a;
    long long res = 0;
    long long one = 1LL << 62;
    while (one > op) one >>= 2;
    while (one) {
        if (op >= res + one) {
            op -= res + one;
            res += 2*one;
        }
        res >>= 1;
        one >>= 2;
    }
    return res;
}

int main() {
    long long tot = R*R/2 + R*R;
    cout << tot << endl;
    long long r = R/8;
    double M = sqrt(2)*r;
    long long tmp = 0;
    long long tmp2 = 0;
    tmp += r*(r+1) - 1;  
    for (long long i = r+1; i < M; ++i) {
        long long m = isqrt(2*r*r - i*i);
        if (m*m == 2*r*r - i*i) m -= 1;
        tmp2 += m;
    }
    tmp += 2*tmp2 + (long long) M - r;
    tot += 4*tmp - (r-1)*2;
    cout << tot << endl;
    return 0;
}
