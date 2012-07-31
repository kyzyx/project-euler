#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#define fori(N) for(int i=0; i<N; i++)
#define forj(N) for(int j=0; j<N; j++)

using namespace std;
typedef mpz_class BigInt;

unsigned long z;

    //string digs;
bool in[10];
bool in2[10];
unsigned long digsa, digsb, nd=1, ntmp;
mpz_t mod;
mpz_t tmp;
mpz_t ten;
int i;
int tmpdig;

bool isPD(mpz_t n){
    //digs = n.get_str();
    digsa = mpz_mod_ui(tmp, n, 1000000000L);
    ntmp = mpz_sizeinbase(n,10) - 10;
    if(ntmp != nd){
	    mpz_pow_ui(mod,ten,ntmp);
	    nd = ntmp;
	}
    mpz_tdiv_q(tmp, n, mod);
    //digsb =mpz_mod_ui(tmp, tmp, 1000000000L);
	digsb = mpz_get_ui(tmp);

	//cout << digsa << " " << digsb << endl;
    //digsb = n/(mpz_pow_ui());
    for(i=0; i<10; ++i){
         in[i] = false;
         in2[i] = false;
    }
    in[digsa%10] = true;
	tmpdig = digsb%10;
	digsa /= 10;
	digsb /= 10;

    for(i=1; i<9; ++i){
        if(in[digsa%10] || in2[digsb%10]) return false;
        in[digsa%10] = true;
        in2[digsb%10] = true;
    	digsa /= 10;
    	digsb /= 10;
    }
    if(digsb != 0) in2[digsb] = true;
    else in2[tmpdig] = true;
    for(i=1; i<10; ++i) if(!in[i] || !in2[i]) return false;
    return true;
}


int main(){
	mpz_t f1, f2, tmp2, tst;
	mpz_init_set_ui(ten,10);
	mpz_init_set_ui(f1,1);
	mpz_init_set_ui(f2,1);
	mpz_init_set_ui(mod, 10);
	mpz_init(tmp);
	mpz_init(tmp2);

	//mpz_init_set_str(tst,"123456789555123456789", 10);
	//if(isPD(tst)) cout << "Good" << endl;

	//cin.get();
    for(z = 3; z<2000000000L; ++z){
        mpz_set(tmp, f1);
        mpz_set(f1, f2);
        mpz_add(f2, f2,tmp);
        if(z<2749) continue;
        if(isPD(f2)) {
            cout << z << " is first and last pandigital" << endl;
            break;
        }
        if(z%10000 == 0) cout << z << endl;
    }

    return 0;
}
