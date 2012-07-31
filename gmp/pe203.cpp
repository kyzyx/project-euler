#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#define fori(n) for(int i=0; i<n; i++)
#define forj(n) for(int j=0; j<n; j++)
#define N 51

using namespace std;
//typedef unsigned long BigInt;
typedef mpz_class BigInt;

int primes[15];
int np = 0;

int nfacs[N][15];
BigInt factorial[N][N];

void init(){
	bool isprime[N];
	for(int i=0; i<N; i++) isprime[i] = true;
	for(int i=2;i<N;i++){
		if(isprime[i]){
			for(int j=2*i; j<N; j+=i) isprime[j] = false;
			primes[np++] = i;
		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<np; j++){
			nfacs[i][j] = 0;
		}
	}
	int currp;
	for(int i=2; i<N; i++){
		for(int j=0; j<np && primes[j] <= i; j++){
			currp = primes[j];
			while(currp<=i){
				nfacs[i][j] += i/currp;
				currp *= primes[j];
			}
		}
	}

	for(int i=0; i<N; i++){
		factorial[i][0] = 1;
		factorial[i][i] = 1;
		for(int j=1; j<i; j++){
			factorial[i][j] = factorial[i-1][j-1]+factorial[i-1][j];
		}
	}
}

bool squarefree(int n, int k){
	for(int i=0; i<np && primes[i] <= n; i++){
		if(nfacs[n][i] - nfacs[k][i] - nfacs[n-k][i] > 1) return false;
	}
	return true;
}

BigInt checked[N*N];
int currn = 0;

int main(){
	init();
	//cout << np << endl;
	BigInt total = 0;
	int k;
	for(int i=0; i<N; i++){
		for(int j=0; j<=i; j++){
			if(squarefree(i,j)){
				for(k=0; k<currn; k++){
					if(checked[k] == factorial[i][j]) break;
				}
				if(k==currn){
					checked[currn++] = factorial[i][j];
					total += factorial[i][j];
				}
			}
		}
	}

	//for(int i=0; i<currn;i++) cout << checked[i] << " ";
	cout << total << endl;
	//cin.get();

	return 0;
}
