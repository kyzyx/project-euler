/* a^2 = z + xy, y^2 = xz
1. Prove that remainder must be smallest
2. Let z = mn^2 for squarefree m
3. n^2 + nk^3 = a^2 = loop through all 10^4 k, n

Time: 4s preprocess, 38s execute
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#define mp make_pair

using namespace std;
typedef unsigned long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

vll cubes;
map<ll, vll> cands;
map<ll, ll> cbrt;
set<ll> res;

int main() {
    ll lim = 1000000000000ULL;
    ll lim2 = 1000000ULL;
    ll lim3 = 10000ULL;
    
    for(ll i = 0; i < lim3; ++i) {
        cubes.push_back(i*i*i);
        cbrt.insert(mp(i*i*i, i));
    }
    for(ll i = 1; i < lim2; ++i) {
        for(ll m = 1; m*m*i < lim2; ++m) {
            cands[m*i*i].push_back(m*m*m*m*i*i);
        }
    }
    cout << "Done prep" << endl;
    /*for(ll i = 1; i < lim2; ++i) {
        for(ll m = 1; m*m*i < lim2; ++m) {
            if (m*m*m*m*i*i < lim) {
                cands[m*i*i] += m*m*m*m*i*i;
            }
        }
    }*/
    
    ll tot = 0;
    ll tst, tmp;
    for(int i = 1; i < lim3; ++i) {
        for(ll j = 1; j < i; ++j) {
            tst = j*cubes[i] + j*j;
            map<ll, vll>::iterator it = cands.find(tst);
            if (it != cands.end()) { 
                for (int k = 0; k < (*it).second.size(); ++k) {
                    // Determine m
                    ll m = cbrt[(*it).second[k]/(*it).first];
                    if (m*j > i) continue;
                    //cout << (*it).second[k] << " = " << m*m*m*j*j << " + " << m*m*j*i << "*" << m*i*i << " " << i << " " << j << " " << m << endl;
                    res.insert((*it).second[k]);
                }
                cands.erase(tst);
            }
        }
        if (i%100 == 0) cout << i << endl;
    }
    set<ll>::iterator it;
    for(it = res.begin(); it != res.end(); ++it) {
        tot += *it;
    }
    cout << tot << endl;
    
    cin.get();
    return 0;
}
