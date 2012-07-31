#include <iostream>
#include "util.h"
#include <gmp.h>
#include <gmpxx.h>
#define fori(N) for(int i=0; i<N; i++)
#define forj(N) for(int j=0; j<N; j++)
#define Fori(m,n) for(int i=m; i<n; i++)
#define N 40000000

using namespace std;
typedef mpz_class BigInt;

int main(){
    BigInt p(11);
    BigInt resa, resb, pp;
    BigInt ul("10000000000");
    
    for(unsigned long i=5; true; i++){
        resa = p-1;
        resb = p+1;
        pp = p*p;
        mpz_powm_ui(resa.get_mpz_t(), (resa).get_mpz_t(), i, pp.get_mpz_t());
        mpz_powm_ui(resb.get_mpz_t(), (resb).get_mpz_t(), i, pp.get_mpz_t());
        
        if((resa + resb) % pp > ul){
             cout << i << endl;
             break;
        }
        
        mpz_nextprime(p.get_mpz_t(), p.get_mpz_t());
        if(i%3000 == 0) cout << i << endl;
    }
    
   // cin.get();
    return 0;
}
