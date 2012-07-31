#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll MOD = 100000000;

class sqmatrix {
    public:
        sqmatrix() {
            d = 0;
        }
        sqmatrix(int dd) {
            d = dd;
            for(int i = 0; i < d; ++i) {
                m.push_back(vll(d,0));
                m[i][i] = 1;
            }
        }
        sqmatrix(ll* mat, int dd) {
            d = dd;
            for(int i = 0; i < d; ++i) {
                m.push_back(vll(d,0));
                for(int j = 0; j < d; ++j) {
                    m[i][j] = mat[i*d+j];
                }
            }
        }
        
        sqmatrix operator*(sqmatrix& b) {
            if (d != b.d) {
                cout << "Error! Invalid matrix dimensions!" << endl;
                return sqmatrix(0);
            }
            sqmatrix result(d);
            for(int i = 0; i < d; ++i) {
                for(int j = 0; j < d; ++j) {
                    result.m[i][j] = 0;
                    for(int k = 0; k < d; ++k) {
                        result.m[i][j] = result.m[i][j] + m[i][k]*b.m[k][j];
                        if (MOD) result.m[i][j] %= MOD;
                    }
                }
            }
            return result;
        }
        
        ll& get(int a, int b) {
            return m[a][b];
        }
        
        void print() {
            for(int i = 0; i < d; ++i) {
                for(int j = 0; j < d; ++j) {
                    cout << m[i][j] << " ";
                }
                cout << endl;
            }
        }
    private:
        vector<vll > m;
        int d;
};

int states = 7;

ll adjm[] = 
                      {0,0,0,1,1,0,0,
                       0,0,0,1,1,0,0,
                       0,0,0,1,0,0,0,
                       1,1,1,0,0,1,1,
                       0,0,0,1,1,0,0,
                       1,0,0,0,0,1,0,
                       0,1,0,0,0,0,1};

int startstate = 3;
bool endstate[]   = {0, 0, 0, 1, 0, 1, 0};


int main() {
    ll n = 1000000000000LL;
    
    n -= 1;
    sqmatrix res(states);
    sqmatrix cp(adjm, states);
    
    
    while(n>0) {
        if (n&1) res = res*cp;
        cp = cp*cp;
        n >>= 1;
    }
    
    res.print();
    ll ans = 0;
    for(int i = 0; i < states; ++i) {
        if (endstate[i]) {
            ans += res.get(startstate,i);
        }
    }
    
    cout << (MOD?ans%MOD:ans) << endl;
    cin.get();
    return 0;
}
