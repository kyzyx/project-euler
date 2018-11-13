#include <iostream>
#include <queue>
#define N 16

using namespace std;

typedef unsigned long long ll;

long long powmod(long long a, long long b, int m) {
  long long res = 1;
  long long pow = a;

  while(b > 0) {
    if (b&1) {
      res = res*pow % m;
    }
    pow = pow*pow % m;
    b >>= 1;
  }

  return res;
}

ll ans(ll n, ll mod) {
    vector<int> x(4,0);
    vector<int>::reverse_iterator it;
    for (int i = 0; n && i < 4; i++) {
        x[3-i] = n&1;
        n >>= 1;
    }
    ll ret = 2;
    cout << ret << ": ";
    for (int i = 0; i < x.size(); i++) cout << x[i] << " ";
    cout << endl;

    // Setup
    ret += x.back() + 1;
    ret %= mod;
    x.back() = 0;
    for (it = x.rbegin(); it != x.rend() && *it == 0; it++) {
        *it = ret - 1;
    }
    if (it != x.rend()) {
        *it -= 1;
    }
    cout << ret << ": ";
    for (int i = 0; i < x.size(); i++) cout << x[i] << " ";
    cout << endl;

    ll pp = 0;
    ll tr = ret;
    while (x[0] >= 0) {
        while (x[1] >= 0) {
            pp += x[2] + 1;
            tr = ret * powmod(2, pp, mod);
            x[2] = tr-1;
            x[1]--;
        }
        x[1] = tr-1;
        x[0]--;
    }
    tr -= 3;
    return tr;
}

int main() {
    ll n = 1;
    for (int i = 2; i < N; i++) {
        ll k = ans(i, 1000000000LL);
        cout << "Answer " << i << ": " << k << endl;
        cin.get();
        n += k;
    }
    cout << n << endl;
}
