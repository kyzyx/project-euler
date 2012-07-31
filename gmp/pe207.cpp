#include <iostream>
#include <gmpxx.h>
#include <gmp.h>
#define fori(n) for(int i=0; i<n; i++)
#define forj(n) for(int j=0; j<n; j++)
#define MAX 24

using namespace std;
typedef mpz_class BigInt;
//typedef unsigned long BigInt;

int main(){
	BigInt curr = 2;
	int i;
	BigInt k, nt;
	for(i=2; i<MAX; i++){
		curr *= 2;
		k = ((curr-1)*(curr-1) - 1)/4;
		nt = (curr-2)/2;
		cout << i-1 << "/" << nt << "\t" << k << endl;
		if((i-1)*12345 < nt) break;
	}

	cin.get();
	for(BigInt a = (curr/2-2)/2; a<nt; a++){
		if((i-2)*12345 < a){
			cout << a << ":" << a*a + a << endl;
			break;
		}
	}

    return 0;
}

