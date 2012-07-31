#include <iostream>
#include <fstream>
#include <gmp.h>
#include <gmpxx.h>
#define fori(n) for(int i=0; i<n; i++)
#define forj(n) for(int j=0; j<n; j++)
#define N 10000000

using namespace std;

int numPrimes = 0;
int primes[N/3];
bool isprime[N];

bool isPrime(int n){
    mpz_t tmp;
    mpz_init_set_si(tmp, n);
    return mpz_probab_prime_p(tmp, 15);
}

void genPrime(){
	fori(N)isprime[i] = true;
	for(int i=2; i<N; i++){
		if(isprime[i]){
			primes[numPrimes++] = i;
			for(int j=i*2; j<N; j+= i){
				isprime[j] = false;
			}
		}
	}
}

int powlog10(int n){
	if(n < 10) return 10;
	if(n < 100) return 100;
	if(n < 1000) return 1000;
	if(n < 10000) return 10000;
	if(n < 100000) return 100000;
	if(n < 1000000) return 1000000;
}

int main(){
	genPrime();
	cout << "Done generating primes" << endl;
	bool done=false;

	for(int i=1; primes[i]<10000 && !done; i++){
		for(int j=i+1; primes[j]<10000 && !done; j++){
			if(!isPrime(primes[i]*powlog10(primes[j])+primes[j]) ||
			   !isPrime(primes[j]*powlog10(primes[i])+primes[i])) continue;
			for(int k=j+1; primes[k]<10000  && !done; k++){
				if(!isPrime(primes[i]*powlog10(primes[k])+primes[k]) ||
			       !isPrime(primes[k]*powlog10(primes[i])+primes[i])) continue;
				if(!isPrime(primes[k]*powlog10(primes[j])+primes[j]) ||
			       !isPrime(primes[j]*powlog10(primes[k])+primes[k])) continue;
				for(int l=k+1; primes[l]<10000 && !done; l++){
					if(!isPrime(primes[i]*powlog10(primes[l])+primes[l]) ||
			           !isPrime(primes[l]*powlog10(primes[i])+primes[i])) continue;
					if(!isPrime(primes[l]*powlog10(primes[j])+primes[j]) ||
			           !isPrime(primes[j]*powlog10(primes[l])+primes[l])) continue;
					if(!isPrime(primes[l]*powlog10(primes[k])+primes[k]) ||
			           !isPrime(primes[k]*powlog10(primes[l])+primes[l])) continue;
					for(int m=l+1; primes[m]<10000 && !done; m++){
						if(!isPrime(primes[i]*powlog10(primes[m])+primes[m]) ||
						   !isPrime(primes[m]*powlog10(primes[i])+primes[i])) continue;
						if(!isPrime(primes[m]*powlog10(primes[j])+primes[j]) ||
			               !isPrime(primes[j]*powlog10(primes[m])+primes[m])) continue;
						if(!isPrime(primes[m]*powlog10(primes[k])+primes[k]) ||
			               !isPrime(primes[k]*powlog10(primes[m])+primes[m])) continue;
						if(!isPrime(primes[l]*powlog10(primes[m])+primes[m]) ||
						   !isPrime(primes[m]*powlog10(primes[l])+primes[l])) continue;
						cout << primes[i] << " " << primes[j] << " " << primes[k];
						cout << " " << primes[l] << " " << primes[m] << endl;
						done=true;
					}
				}
			}
		}
	}

	//cin.get();
	return 0;
}
