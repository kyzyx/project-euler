/* a^2 = z + xy, y^2 = xz
1. Prove that remainder must be smallest
a^2 = kmn*km^2 + kn^2 = k^2 m^3 n + kn^2, m>n
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>

using namespace std;
typedef unsigned long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

vll cubes;
set<ll> cands;
set<ll> res;

int gcd(int a, int b) {
    int tmp;
    while (b) {
        tmp = a;
        a = b;
        b = tmp%b;
    }
    return a;
}

bool isRes[256];

bool isSquare(ll n) {
    if (!isRes[n&0xFF]) return false;
    ll rt = sqrt(n);
    return rt*rt == n;
}

int main() {
    ll lim = 1000000000000ULL;
    ll lim3 = 10000ULL;
    
    for(int i = 0; i < 256; i++) {
        isRes[i] = false;
    }
    for(int i = 0; i < 256; i++) {
        isRes[(i*i)%256] = true;
    }
    
    ll tot = 0;
    ll t, jj;
    for(ll i = 2; i < lim3; ++i) {
        for(ll j = 1; j < i && i*i*i*j + j*j < lim; ++j) {
            if (gcd(i, j) != 1) continue;
            t = i*i*i*j;
            jj = j*j;
            for(ll k = 1; t*k*k + k*jj < lim; ++k) {
                if (isSquare(t*k*k + k*jj)) {
                    tot += t*k*k + k*jj;
                }
                
            }
        }
        if (i%100 == 0) cout << i << endl;
    }
    
    cout << tot << endl;
    
    cin.get();
    return 0;
}
