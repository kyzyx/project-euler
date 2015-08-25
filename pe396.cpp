#include <iostream>
#include <queue>
#include "util.h"
#define N 16

using namespace std;

typedef unsigned long long ll;

deque<ll>::reverse_iterator rit;
deque<ll> x;

void printx() {
    for (rit = x.rbegin(); rit != x.rend(); rit++) cout << *rit << " ";
    cout << endl;
}

ll ans(ll n, ll mod) {
    x.clear();
    while (n) {
        x.push_back(n&1);
        n >>= 1;
    }
    ll ret = 2;
    deque<ll>::iterator it;
    cout << ret << ": ";
    printx();
    while (x.size() > 1) {
        ret += x.front() + 1;
        ret %= mod;
        x.front() = 0;
        for (it = x.begin(); it != x.end() && *it == 0; it++) {
            *it = ret - 1;
        }
        if (it != x.end()) {
            *it -= 1;
            if (*it == 0 && it == x.end() - 1) x.pop_back();
        }
    cout << ret << ": ";
        printx();
        cin.get();
    }
    ret += x.front();
    ret -= 2;
    return ret;
}

int main() {
    ll n = 0;
    for (int i = 1; i < N; i++) {
        ll k = ans(i, 1000000000LL);
        cout << "Answer " << i << ": " << k << endl;
        n += k;
    }
    cout << n << endl;
}
