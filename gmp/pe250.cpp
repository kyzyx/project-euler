#include <iostream>
#include "util.h"
#include <gmp.h>
#include <gmpxx.h>

using namespace std;
typedef mpz_class BigInt;

//int rem[250];
unsigned int rems[250250];

BigInt dp[251][250250];

int main(){
    //fori(250) rem[i] = 0;
    BigInt r;
    BigInt twofifty(250);
	BigInt mod("10000000000000000");

	cout << "Done malloc" << endl;
    for(BigInt i=1; i<250250; i++){
        mpz_powm(r.get_mpz_t(), i.get_mpz_t(), i.get_mpz_t(), twofifty.get_mpz_t());
        //++rem[r.get_ui()];
    	rems[i.get_ui()] = r.get_ui();
    }

	for(int i=0; i<20; i++) cout << rems[i] << endl;

	for(int i=0; i<250; i++){
		for(int j=0; j<250250; j++){
			dp[i][j] = 0;
		}
	}
	cout << "ready to start dp" << endl;
	cin.get();
	dp[rems[0]][0] = 1;
	for(int i=1; i<250250; i++){
		for(int j=0; j<250; j++){
			dp[j][i] = dp[j][i-1] + dp[(j-rems[i]+250)%250][i-1];
			if(rems[i] == j) ++dp[j][i];
			if(dp[j][i] > mod) dp[j][i] %= mod;
		}
		if(i%1000 == 0) cout << i << endl;
	}
	cout << dp[0][250249]%mod << endl;
    return 0;
}
