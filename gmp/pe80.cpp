#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#define fori(n) for(int i=0; i<n; i++)
#define ND 100

using namespace std;
typedef mpz_class BigInt;

int firstDig[101];

int sumsqrt(int n){
	if(n>99||firstDig[n]==0) return 0;
	BigInt tridiv(20*firstDig[n]);
	BigInt div(100*(n-firstDig[n]*firstDig[n]));
	char digs[ND];
	int z = 0;
	int j = 0;

	fori(ND+1){
		//cout << tridiv <<" " << div <<endl;
		for(j=0; j<10; j++){
			if((tridiv+j+1)*(j+1) > div) break;
		}
		digs[i] = j;
		div = (div-(tridiv+j)*j)*100;
		tridiv = (tridiv+2*j)*10;
	}
	cout << firstDig[n] << ".";
	int t = firstDig[n];
	fori(ND-1){
		t += digs[i];
		cout << (int)digs[i];
	}
	cout << endl;
	return t;
}

int main(){

	fori(10){
		for(int j=i*i+1; j<(i+1)*(i+1); j++){
			firstDig[j] = i;
		}
		firstDig[i*i] = 0;
	}
	long sum = 0;
	fori(100){
		sum += sumsqrt(i);
		cout << i << endl;
	}
	cout << sum << endl;

	return 0;
}
