#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#include <string>

using namespace std;
typedef mpz_class BigInt;

string test(BigInt t, int l=30){
	string ret = "";
	for(int i=0; i<l; i++){
		if(t%3 == 0){
			ret += "D";
			t/=3;
		}
		else if(t%3 == 1){
			ret += "U";
			t = (4*t+2)/3;
		}
		else{
			ret += "d";
			t = (2*t-1)/3;
		}
	}
	return ret;
}

int main(){
	//BigInt lim("1000000");
	BigInt lim("1000000000000000");
    //string ins = "DdDddUUdDD";
    string ins = "UDDDUdddDDUDDddDdDddDDUDDdUUDd";
    /*
    string ins = "UUDd";
    BigInt lim = 100;
*/
    BigInt mod = 3;
    BigInt rem;
    if(ins[ins.length()-1] == 'D') rem = 0;
    else if(ins[ins.length()-1] == 'U') rem = 1;
    else rem = 2;
	//cout << rem << " mod " << mod << endl;
    for(int i=ins.length()-2; i>=0; i--){
		mod *= 3;
		rem *= 3;
        if(ins[i] == 'U'){
        	if(rem < 2) rem = rem-2+mod;
        	else rem = rem-2;
        	while(rem%4 != 0) rem += mod;
        	rem /= 4;
        }
        else if(ins[i] == 'd'){
			rem = rem+1;
        	while(rem%2 != 0) rem += mod;
        	rem /= 2;
        }
        rem = rem%mod;
        //mod *= 3;
        //cout << rem << " mod " << mod << endl;
    }
    //rem = rem%mod;
	BigInt i;
	for(i=rem;i<lim; i+= mod);
	cout << "Smallest is " << i << " congruent to " << rem << " mod " << mod<< endl;
	//test(i, ins.length());
}
