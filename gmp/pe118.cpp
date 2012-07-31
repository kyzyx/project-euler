#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#include <algorithm>

using namespace std;
typedef mpz_class BigInt;
bool prime[1000000];
int primes[100000];
int nump = 0;

int digits[] = {1,2,3,4,5,6,7,8,9};
//int digits[] = {1,2,3};
int perms[] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};

void init() {
	for(int i = 0; i < 1000000; i++) prime[i] = true;
	prime[1] = false;
	for(int i = 2; i < 1000000; i++) {
		if(!prime[i]) continue;
		for(int j = i*2; j < 1000000; j += i) {
			prime[j] = false;
		}
		primes[nump++] = i;
	}
}

bool isPrime(int a, int b) {
	unsigned int n;
    n = digits[a];
	for(int i = a; i < b; i++) {
		n *= 10;
		n += digits[i+1];
	}
	if(n<1000000) return prime[n];
	else {
		BigInt num = n;
		return mpz_probab_prime_p(num.get_mpz_t(), 9);
	}
}

double countN(int start, int a, int numCommas) {
	//cout << "countN: " << start << "-" << a << "(" << numCommas << ") ";
	if(a == 8) {
	//if(a == 2) {
		if(isPrime(start, a)) {
	//		cout << perms[numCommas] << endl;
			return 1./perms[numCommas];
		}
		else {
	//		cout << 0 << endl;
			return 0;
		}
	}
	double c = 0, b;
	if(isPrime(start, a)) {
		c = countN(a+1, a+1, numCommas+1);
	}
	b = countN(start, a+1, numCommas);
	//cout << c << "+" << b << endl;
	return c+b;
}

int main() {
	init();
	double total = 0;
	int z = 0;
	do {
		//for(int i = 0; i < 3; i++) cout <<digits[i];
		//cout << endl;
		if(z%50000==49999) cout << z << endl;
		total += countN(0,0,0);
		++z;
	} while(next_permutation(digits, digits+9));

	cout << total << endl;
}
