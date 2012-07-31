// 4s
// Correct solution: DP (dp[i][j] is prob of being croak j at position i
#include <iostream>

using namespace std;

bool isprime[501];

char p[] = "PPPPNNPPPNPPNPN";

long long numpaths = 0;
long long ps = 0;

long long gcd(long long a, long long b) {
    if (a == 0) return 1;
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    long long u, v, s;
    u = __builtin_ctz(a);
    v = __builtin_ctz(b);
    s = u<v?u:v;
    u = a>>u;
    v = b>>v;
    while (u!=v) {
        if(u>v) {
            u -= v;
            u >>= __builtin_ctz(u);
        } else {
            v -= u;
            v >>= __builtin_ctz(v);
        }
    }
    return u << s;
}

long long prob(int start, int path) {
    int loc = start;
    long long ret = 1;
    for(int i = 0; i < 14; ++i) {
        //cout << loc << (isprime[loc]?'#':'_') << p[i] << ' ';
        if (isprime[loc]) {
            if (p[i] == 'P') ret <<= 1;
        }
        else {
            if (p[i] == 'N') ret <<= 1;
        }
        if (loc == 500) --loc;
        else if(loc == 1) ++loc;
        else if (path&1) ++loc;
        else --loc; 
        path >>= 1;
    }
    if (!isprime[loc]) ret <<= 1;
    return ret;
}

int main() {
    long long numpaths = 14348907LL*500*(1<<14);
    for(int i = 0; i < 501; ++i) {
        isprime[i] = true;
    }
    isprime[1] = false;
    for(int i = 2; i < 501; ++i) {
        if (isprime[i]) {
            for(int j = 2*i; j < 501; j += i) isprime[j] = false;
        }
    }
    
    for(int i = 1; i <= 500; ++i) {
        for(int j = 0; j < (1<<14); ++j) {
            ps += prob(i,j);
        }
    }
    long long g = gcd(numpaths, ps);
    numpaths /= g;
    ps /= g;
    cout << ps << "/" << numpaths << endl;
    cin.get();
    return 0;
}
