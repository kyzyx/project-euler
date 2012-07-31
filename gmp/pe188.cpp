#include <iostream>
#include <gmp.h>
#include <gmpxx.h>

using namespace std;
typedef mpz_class BigInt;


int main(){
    unsigned int MAX = 1855, base = 1777;
    mpz_t mod, exp, curr;
    mpz_init_set_ui(mod, 100000000UL);
    mpz_init_set_ui(exp, base);
    mpz_init_set_ui(curr, base);


    for(int i=1; i<MAX; i++){
		mpz_powm(curr, exp, curr, mod);
	}
	BigInt disp(curr);
	cout << disp << endl;

    return 0;
}
