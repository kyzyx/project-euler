#include <iostream>
#include <gmp.h>
#include <gmpxx.h>

using namespace std;

typedef mpz_class BigInt;

int main() {
    // x + 10^n*a = k*(10x + a)
    // x = a (10^n - k)/(10k-1)
    // a, k < 10
    
    BigInt sum = 0;
	BigInt x;
    BigInt pow10[100];
    pow10[0] = 1;
    for(int i = 1; i < 100; i++) {
        pow10[i] = 10*pow10[i-1];
    }
    
    for(int i = 1; i < 100; i++) {
        for(int a = 1; a < 10; a++) {
            for(int k = 1; k < 10; k++) {
                if (a*(pow10[i] - k) % (10*k - 1) == 0) {
					x = (a*(pow10[i] - k)/(10*k - 1)); 
					if (x < pow10[i-1]) continue;
                    sum += (10*x+a) % 100000;
					//cout << x << " " << 10*x + a << endl;
                }
            }
        }
    }
    cout << sum << endl;
}
