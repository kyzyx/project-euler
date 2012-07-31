/* Implements chinese remainder theorem and extended euclidean algorithm as described in wikipedia
*/

#include <iostream>
#define MAX 1000

#include <gmp.h>
#include <gmpxx.h>


using namespace std;
//typedef long BigInt;
typedef mpz_class BigInt;

int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43};
int np = 14;
BigInt N = 1;

BigInt euclidean(BigInt b, BigInt a){
	BigInt table[MAX][4];
	int i;
	table[0][0] = 1;
	table[0][1] = 0;
	table[0][2] = a;
	table[0][3] = 0;
	table[1][0] = 0;
	table[1][1] = 1;
	table[1][2] = b;
	table[1][3] = a/b;
	/*for(int j=0; j<4; j++){
			cout << table[0][j] << " ";
	}
	cout << endl;
	for(int j=0; j<4; j++){
				cout << table[1][j] << " ";
	}
	cout << endl;
	*/for(i=2; table[i-1][2] != 1; i++){
		if(i==MAX){
			cout << "Not long enough!!!" << endl;
			cin.get();
		}
		table[i][0] = table[i-2][0] - table[i-1][3]*table[i-1][0];
		table[i][1] = table[i-2][1] - table[i-1][3]*table[i-1][1];
		table[i][2] = table[i-2][2] % table[i-1][2];
		table[i][3] = table[i-1][2] / table[i][2];
		/*for(int j=0; j<4; j++){
			cout << table[i][j] << " ";
		}
		cout << endl;*/
	}
	//cout << "---------------\n" << table[i-1][0] << "*" << a << " + " << table[i-1][1] << "*" << b << " = 1" << endl;
	return table[i-1][0]*a;
}

BigInt findx(string mods){
	BigInt ret = 0;
	for(int i=0; i<np; i++){
		ret += mods[i]*euclidean(primes[i], N/primes[i]);
	}
	return ret;
}

BigInt addProd(int n, string mods){
	BigInt ret = 0;
	if(n == np){
		BigInt tmp = (findx(mods)%N + N)%N;
		//for(int i=1; tmp*i < N; i++) ret += tmp*i;
		cout << tmp << endl;
		return tmp;
	}

	switch(n){
		case 3: mods[n] = 2;
				ret += addProd(n+1, mods);
				mods[n] = 4;
				ret += addProd(n+1, mods);
				break;
		case 5: mods[n] = 3;
				ret += addProd(n+1, mods);
				mods[n] = 9;
				ret += addProd(n+1, mods);
				break;
		case 7: mods[n] = 7;
				ret += addProd(n+1, mods);
				mods[n] = 11;
				ret += addProd(n+1, mods);
				break;
		case 10:mods[n] = 5;
				ret += addProd(n+1, mods);
				mods[n] = 25;
				ret += addProd(n+1, mods);
				break;
		case 11:mods[n] = 10;
				ret += addProd(n+1, mods);
				mods[n] = 26;
				ret += addProd(n+1, mods);
				break;
		case 13:mods[n] = 6;
				ret += addProd(n+1, mods);
				mods[n] = 36;
				ret += addProd(n+1, mods);
				break;
	}
	mods[n] = 1;
	ret += addProd(n+1,mods);
	return ret;
}

int main(){
	for(int i=0; i<np; i++){
		N *= primes[i];
	}
	cout << N << endl << "----------" << endl;

	string m = "11111111111111";

	cout << addProd(0, m)-1 << endl;

    return 0;
}