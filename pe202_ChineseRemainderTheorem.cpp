#include <iostream>
#include <vector>

using namespace std;

bool isprime[2000000];
vector<int> primes;

typedef long long ll;
typedef pair<ll,ll> pll;

// Extended Euclidean Algorithm
// Returns x, y such that ax + by = 1
pll eea(ll a, ll b) {
    if (a < b) {
        pll tmp = eea(b,a);
        return make_pair(tmp.second, tmp.first);
    }
    ll x = 0;
    ll y = 1;
    ll cx = 1;
    ll cy = 0;
    while (b!=0){
        ll q = a/b;
        ll tmp = a;
        a = b;
        b = tmp%b;
        
        tmp = x;
        x = cx - q*x;
        cx = tmp;
        
        tmp = y;
        y = cy - q*y;
        cy = tmp;
    }
    return make_pair(cx, cy);
}

// Chinese remainder theorem: Returns number of solutions 0 <= x <= lim
// such that x % p[i] = r[i]
ll crt(ll lim, vector<ll>& r, vector<ll>& p) {
    ll N = 1;
    for(int i = 0; i < p.size(); ++i) N *= p[i];
    ll sol = 0;
    for(int i = 0; i < p.size(); ++i) {
        pll rs = eea(p[i], N/p[i]);
        sol += r[i] * N/p[i] * rs.second;
    }
    while (sol < 0) sol += N;
    sol %= N;
    return lim/N + (lim%N>=sol?1:0);
}

long long points(long long row) {
    if (row%3 == 0) return 0;
    long long tmp = row;
    vector<long long> facs;
    for(int i = 0; i < primes.size() && primes[i] < tmp; ++i) {
        if (tmp % primes[i] == 0) {
            while (tmp % primes[i] == 0) {
                tmp /= primes[i];
            }
            facs.push_back(primes[i]);
        }
    }
    if (tmp > 1) {
        facs.push_back(tmp);
    }

    int start = row%3;
    long long c = 0;
    if (start) start = 3 - start;
    for(int i = 0; i < 1 << facs.size(); ++i) {
        int parity = 1;
        if (__builtin_popcount(i)&1) parity = -1;
        long long prod = 1;
        int tmp = i;
        for(int j = 0; j < facs.size(); ++j) {
            if (tmp&1) prod *= facs[j];
            tmp >>= 1;
        }
        vector<ll> a, p;
        a.push_back(start); a.push_back(0);
        p.push_back(3); p.push_back(prod);
        c += parity*crt(row, a, p);
    }
    return c;
}

int main() {
    vector<ll> a, b;
    a.push_back(2); a.push_back(3); a.push_back(1);
    b.push_back(3); b.push_back(4); b.push_back(5);
    cout << crt(140, a, b) << endl;
    cin.get();
    
  for(int i = 0; i < 200000; ++i) isprime[i] = true;
  for(int i = 2; i < 200000; ++i) {
    if (isprime[i]) {
      primes.push_back(i);
      for(int j = 2*i; j < 200000; j += i) isprime[j] = false;
    }
  }

  long long ref = 12017639147LL;
  long long row = (ref+3)/2;
    cout << row << endl;
  cout << points(row) << endl;
  cin.get();
  return 0;
}
