#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#define MAX 10001

using namespace std;
typedef mpz_class BigInt;

bool terminates[MAX];

void init(){
    for(int i=0; i<MAX; i++) terminates[i] = false;
    terminates[1] = true;
    for(int i=2; i<MAX; i*=2){
        terminates[i] = true;
    }
    for(int i=0; i<MAX; i++){
        if(terminates[i]){
            for(int j=i*5; j<MAX; j*=5){
                terminates[j] = true;
            }
        }
    }
}

BigInt pow(BigInt b, int exp){
    if(exp == 1) return b;
    BigInt r = pow(b, exp/2);
    r *= r;
    if(exp & 1) r *= b;
    return r;
}

int maxparts(int n, int p){
    BigInt maxn = 0, maxd = 1;
    BigInt currn = 1, currd = 1;
    int i;
    for(i=p; i<n; i++){
        currn = pow(n,i);
        currd = pow(i,i);
        if(currn*maxd > maxn*currd){
			maxn = currn;
			maxd = currd;
		}
        else break;
    }
    return i-1;
}

int gcd(int a, int b){
    if(b == 0) return a;
    if(a > b) return gcd(b, a%b);
    else return gcd(a, b%a);
}

int main(){
    init();
    //cout << pow(2,20) << endl;
    long tot = 0;
    int d=1, a;
    for(int i=5; i<MAX; i++){
        d = maxparts(i,d);
        a = gcd(i, d);
        //cout << d << endl;
        //if(d%a != 0) cout << d << "/" << a << endl;
        if(terminates[d/a]) tot -= i;
        else tot += i;
    }

    cout << tot << endl;

    cin.get();
    return 0;
}
