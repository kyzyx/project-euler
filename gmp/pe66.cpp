#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#define fori(n) for(int i=0; i<n; i++)
#define N 1000

using namespace std;
typedef mpz_class BigInt;

int sqrts[N+1];

class term{
    public: BigInt a;  //Term
            BigInt n;  //Root
            BigInt num, den; //(sqrt(n) - num)/ den

            term(){
                a = 1;
                n = 1;
                num = 1;
                den = 1;
            }
            term(int aa, int nn, int xx, int yy){
                a = aa;
                n = nn;
                num = xx;
                den = yy;
            }
			term(BigInt& aa, BigInt& nn, BigInt& xx, BigInt& yy){
                a = aa;
                n = nn;
                num = xx;
                den = yy;
            }
            void set(int aa, int nn, int xx, int yy){
                a = aa;
                n = nn;
                num = xx;
                den = yy;
            }
            term next(){
                term* ret;
                BigInt newDen = ((n-num*num)/den);
                BigInt newTerm = (sqrts[n.get_ui()]+num)/newDen;
                BigInt tmp = -(num-newDen*newTerm);
                ret = new term(newTerm, n, tmp, newDen);
                return *ret;
            }

            term& operator=(const term &b){
                if(this == &b) return *this;
                a = b.a;
                n = b.n;
                num = b.num;
                den = b.den;
                return *this;
            }
            bool operator==(const term& b){
                if(a == b.a && n == b.n && num == b.num && den == b.den) return true;
                else return false;
            }

            void dump(){
                cout << a << " + (sqrt(" << n << ") - " << num << ")/" << den << endl;
            }
};

bool satDioph(BigInt x, BigInt y, int D){
    if(x*x - D*y*y == 1) return true;
    return false;
}

BigInt convergent(int m){
    term t;
    t.set(sqrts[m],m,sqrts[m],1);
    BigInt* a = new BigInt[N];
    BigInt* n = new BigInt[N];
    BigInt* d = new BigInt[N];
    int z=0;

    a[z] = t.a;
    n[z] = a[z];
    d[z] = 1;
    //cout << n[z] << "/" << d[z] << endl;
    if(satDioph(n[z], d[z], m)) return n[z];
    ++z;

    t = t.next();
    a[z] = t.a;
    n[z] = a[z]*n[z-1] + 1;
    d[z] = a[z];
    //cout << n[z] << "/" << d[z] << endl;
    if(satDioph(n[z], d[z], m)) return n[z];
    ++z;
    bool loop = false;

    while(!loop){
        t = t.next();
        a[z] = t.a;
        n[z] = a[z]*n[z-1] + n[z-2];
        d[z] = a[z]*d[z-1] + d[z-2];
        //cout << n[z] << "/" << d[z] << endl;
        //cin.get();
        if(satDioph(n[z], d[z], m)) return n[z];
        ++z;
    }
}

int main(){
    //Init
    fori(31){
        sqrts[i*i] = 0;
        for(int j=i*i+1; j<(i+1)*(i+1) && j<N; j++){
            sqrts[j] = i;
        }
    }


	int maxi = 0;
    BigInt max = 0;
    BigInt curr = 0;
    fori(N+1){
        if(sqrts[i] == 0) continue;
        //else cout << i << ":" << period(i) << endl;
        curr = convergent(i);
        cout << curr << endl;
        if(curr > max){
             max = curr;
             maxi = i;
        }
    }

    cout << maxi << ":" << max << endl;
    cin.get();
    return 0;
}
