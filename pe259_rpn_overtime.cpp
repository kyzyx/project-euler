// 4:00 - Pure brute force
// Correct solution: Generate fractions for subranges and combine ranges
#include <iostream>
#include <vector>
#include <stack>
#include <set>

enum {
    PLUS = 0,
    MINUS,
    TIMES,
    DIVIDE
};

using namespace std;
typedef long long ll;
typedef vector<int>::iterator vii;

long long gcd2(long long a, long long b) {
    if (a == 0) return 1;
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (b > a) return gcd2(b,a);
    while(b>0) {
        long long tmp = a;
        a = b;
        b = tmp%b;
    }
    return a;
}

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

class frac {
    public:
        frac() {
            num = 0;
            den = 1;
        }
        frac(long long a) {
            num = a; den = 1;
        }
        frac(long long a, long long b, bool red=true) {
            if (b < 0) {
                b = -b; a = -a;
            }
            num = a; den = b;
            if (red) reduce();
        }
        
        void reduce() {
            long long g = gcd(num, den);
            num /= g;
            den /= g;
        }
        
        bool isNegative() {
            return num < 0;
        }
        bool isInteger() {
            return den == 1;
        }
        bool isZero() {
            return num == 0;
        }
        long long toInteger() {
            return num/den;
        }
        
        frac reciprocal() {
            if (num < 0) return frac(-den, -num);
            else return frac(den, num);
        }
        frac neg() {
            return frac(-num, den);
        }
        
        frac operator+(frac& b) {
            long long g = gcd(den, b.den);
            long long m = den/g;
            long long n = b.den/g;            
            return frac(m*b.num + n*num, m*n*g);
        }
        frac operator-(frac& b) {
            long long g = gcd(den, b.den);
            long long m = den/g;
            long long n = b.den/g;            
            return frac(n*num - m*b.num, m*n*g);
        }
        frac operator*(frac& b) {
            long long g1 = gcd(num, b.den);
            long long g2 = gcd(b.num, den);
            return frac((num/g1) * (b.num/g2), (den/g2) * (b.den/g1), false);
        }
        frac operator/(frac& b) {
            long long g1 = gcd(num, b.num);
            long long g2 = gcd(b.den, den);
            return frac((num/g1) * (b.den/g2), (den/g2) * (b.num/g1), false);
        }
    
        frac& operator+=(frac& b) {
            long long g = gcd(den, b.den);
            long long m = den/g;
            long long n = b.den/g;            
            num = n*num + m*b.num;
            den = m*n*g;
            reduce();
            return *this;
        }
        frac& operator-=(frac& b) {
            long long g = gcd(den, b.den);
            long long m = den/g;
            long long n = b.den/g;      
            num = n*num - m*b.num;
            den = m*n*g;
            reduce();
            return *this;
        }
        frac& operator*=(frac& b) {
            long long g1 = gcd(num, b.den);
            long long g2 = gcd(b.num, den);
            num = (num/g1) * (b.num/g2);
            den = (den/g2) * (b.den/g1);
            if (den < 0) {
                num = -num;
                den = -den;
            }
            return *this;
        }
        frac& operator/=(frac& b) {
            long long g1 = gcd(num, b.num);
            long long g2 = gcd(b.den, den);
            num = (num/g1) * (b.den/g2);
            den = (den/g2) * (b.num/g1);
            if (den < 0) {
                num = -num;
                den = -den;
            }
            return *this;
        }
        
        void print() {
            cout << num << "/" << den;
        }
    long long num;
    long long den;
};


// ONLY WORKS WITH POSITIVE OPS
ll evalrpn(long long s[], int l, int ops) {
    frac ns[9];
    short lo = -1;
    int t = 0;
    for(int i = 0; i < l; ++i) {
        if (s[i] < 0) {
            frac b = ns[--t];
            frac a = ns[--t];
            switch(ops&3) {
                case PLUS:
                    if (lo == PLUS) return -1;
                    ns[t++] += b;
                    break;
                case MINUS:
                    ns[t++] -= b;
                    break;
                case TIMES:
                    if (lo == TIMES) return -1;
                    ns[t++] *= b;
                    break;
                case DIVIDE:
                    if (b.isZero()) {
                        return -1;
                    }
                    ns[t++] /= b;
            }
            lo = ops&3;
#ifdef DEBUG
            if (DEBUG) {
                if ((ops&3) == 0) cout << "+ ";
                else if ((ops&3) == 1) cout << "- ";
                else if ((ops&3) == 2) cout << "* ";
                else cout << "/ ";
                cout << "("; ns[t-1].print(); cout << ") ";
            }
#endif
            ops >>= 2;    
        }
        else {
            lo = -1;
            ns[t++] = s[i];
#ifdef DEBUG
            if (DEBUG) cout << s[i] << " ";
#endif
        }
    }
#ifdef DEBUG    
    if (DEBUG) cout << endl;
#endif
    if (ns[t-1].isNegative() || !ns[t-1].isInteger()) {
        return -1;
    }
    return ns[t-1].toInteger();
}

set<ll> reachable;
vector<int> opcs[9];
int pow2[20];

void genOps(ll nums[], int n) {
    if (n == 1) {
        reachable.insert(nums[0]);
        return;
    }
    int no = n-1;
    int no2 = 2*no;
    int t = n + no;
    ll rpn[t];
    int c, cn, co;
    for(vii it = opcs[no].begin(); it != opcs[no].end(); ++it) {
        c = 0; cn = 0;
        rpn[c++] = nums[cn++];
        int a = *it;
        for(int i = 0; i < n; ++i) {
            rpn[c++] = nums[cn++];
            co = a%10;
            for(int j = 0; j < co; ++j) rpn[c++] = -1;
            a /= 10;
        }
        //cout << *it << " " << c << "/" << t << " " << cn << "/" << n << endl;
        for(int i = 0; i < pow2[no2]; ++i) {
            ll r = evalrpn(rpn, t, i);
            if (r>=0) {
                reachable.insert(r);
            }
        }
        cout << *it << " ";
    }
    cout << endl;
}

void genNums() {
    ll n[9];
    ll curr = 0;
    int tmp;
    int cnt;
    for(int i = 0; i < pow2[8]; ++i) {
        tmp = i;
        cnt = 0;
        curr = 0;
        for(int j = 1; j < 10; ++j) {
            curr += j;
            if (tmp&1) {
                n[cnt++] = curr;
                curr = 0;
            }
            else curr *= 10;
            tmp >>= 1;
        }
        n[cnt++] = curr/10;
        genOps(n, cnt);
        cout << i << endl;
    }
}

int sd(int n) {
    int r = 0;
    while (n>0) {
        r += n%10;
        n/=10;
    }
    return r;
}

bool isValid(int n) {
    int t = 2;
    while(n>0) {
        t -= n%10;
        if (t < 1) return false;
        n/=10;
        ++t;
    }
    return true;
}

int facs[10];

int facbase(int n) {
    int a = 0;
    int r = 0;
    while(n >= facs[a]) ++a;
    while (a>0) {
        r += n/facs[a];
        r *= 10;
        n = n%facs[a];
        --a;
    }
    return r/10;
}

int main() {
    facs[0] = 1;
    for(int i = 1; i < 10; ++i) facs[i] = facs[i-1]*i;
    long long pow10[10];
    pow2[0] = 1;
    pow10[0] = 1;
    for(int i = 1; i < 10; ++i) pow10[i] = pow10[i-1]*10;
    for(int i = 1; i < 20; ++i) pow2[i] = pow2[i-1]<<1;
    
    //Test evalrpn()
    long long tst[13];
    tst[0] = 1;
    tst[1] = 23;
    tst[2] = -1;
    tst[3] = 4;
    tst[4] = 5;
    tst[5] = -1;
    tst[6] = 6;
    tst[7] = -1;
    tst[8] = -1;
    tst[9] = 78;
    tst[10] = 9;
    tst[11] = -1;
    tst[12] = -1;
    
    int ops = 3 + (2<<2) + (1<<4) + (2<<6) + (1<<8) + (2<<10);
    cout << evalrpn(tst, 13, ops) << endl;
    cin.get();
    // Generate all the valid partitions => factorial base representation
    for(int i = 1; i < 362880; ++i) {
        int n = facbase(i);
        int d = sd(n);
        if (d > 8 || n >= pow10[d] || n<pow10[d-1] || !isValid(n)) continue;
        opcs[d].push_back(n);
    }
    genNums();
    
    ll sum = 0;
    for(set<ll>::iterator it = reachable.begin(); it != reachable.end(); ++it) {
        sum += *it;
    }
    cout << sum << endl;
    cin.get();
    return 0;
}
