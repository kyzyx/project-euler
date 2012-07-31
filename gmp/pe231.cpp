#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#define MAX 20000001
#define M 5000001

using namespace std;

bool isprime[MAX];
long primes[2000000];
int np = 0;

void init(){
    for(int i=0; i<MAX; i++) isprime[i] = true;
    for(int i=2; i<MAX; i++){
        if(isprime[i]){
            for(int j=2*i; j<MAX; j+=i) isprime[j] = false;
            primes[np++] = i;
        }
    }
}

mpz_class lm(mpz_class low, mpz_class fac){
    return fac*(low/fac + 1);
}

int main(){
    init();
    cout << "Done Init " << np << endl;
    long* numfac = new long[np];
    mpz_class tot = 0;
    mpz_class tmp;
    mpz_class mm = MAX, m = M;
    for(int i=0; i<np; i++) numfac[i] = 0;
    for(long i=0; i<np; i++){
        for(mpz_class j=primes[i]; j<mm; j*=primes[i]){
            for(mpz_class k=lm(mm-m, j); k<mm; k+=j){
                numfac[i]++;
                //cout << primes[i] << "++ at " << k << endl;
            }
            for(mpz_class k=j; k<m; k+=j){
                numfac[i]--;
                //cout << primes[i] << "-- at " << k << endl;
            }
        }
        tmp = primes[i];
        tot += tmp*numfac[i];
        //cout << primes[i] << ":" << numfac[i] << endl;
        //cin.get();
    }
    cout << tot << endl;

    cin.get();
    return 0;
}
