#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#include <algorithm>
#include <cmath>
#define N 10

using namespace std;
typedef mpz_class BigInt;


bool asc(int n) {
	int last = 10;
	while (n > 0) {
		if (n%10 > last) return false;
		else last = n%10;
		n /= 10;
	}
	return true;
}

int main(){
	BigInt total = 0;
	BigInt min("1000000000");
	//BigInt min(1000);
	for(int n = 0; n < 10; n++) {
		for(int rep = N; rep > 1; rep--) {
			bool isprime = false;
			BigInt sum = 0;

			char number[N+1];

			for(int j = 0; j < pow(10, N - rep); j++) {
				if (!asc(j)) continue;
				int a = j;
				for(int b = 0; b < rep; b++) {
					number[b] = '0' + n;
				}
				for(int k = 0; k < N-rep; k++) {
					number[k+rep] = a%10 + '0';
					a/=10;

				}
				sort(number, number + N);
				do {
					if (number[0] == '0') continue;
					//cout << number << endl;
					BigInt p(number);
					if (p < min) continue;
					if (mpz_probab_prime_p(p.get_mpz_t(), 7)) {
						cout << p << endl;
						isprime = true;
						sum += p;
					}
				} while(next_permutation (number, number + N));
			}
			
			if (isprime) {
				total += sum;
				cout << "For digit " << n << ", max reps = " << rep << endl;
				break;
			}
		}
	}	
	cout << "The total sum over all max reps is " << total << endl;
    return 0;
}
