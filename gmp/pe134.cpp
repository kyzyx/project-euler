#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#define MAX 1000005

using namespace std;

bool isprime[MAX];
mpz_class pos[1000];
mpz_class primes[200000];
mpz_class d1, d2;
int np = 0;

void init(){
    for(int i=0; i<MAX; i++) isprime[i] = true;
    for(int i=2; i<MAX; i++){
        if(isprime[i]){
            for(int j=2*i; j<MAX; j+=i) isprime[j] = false;
            primes[np++] = i;
        }
    }
}

unsigned long pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

int nd(mpz_class n) {
    for(int i = 0; i < 7; i++) {
        if(n < pow10[i]) return i;
    }
    return 7;
}

// divides b, ends with a
// Construct digit by digit
mpz_class endsWith(mpz_class a, mpz_class b) {
    int last1 = 0;
    int last2 = 0;
    int z = 0;
    for(int d = 0; d < 10; d++) {
        if((b*d)%10 == a%10) {
            if(a<10) return d;
            pos[z++] = d;
            //cout << d << " ";
        }
    }
    last2 = z;
    for(int digit = 1; digit < nd(a)+1; digit++) {
        //cout << digit << endl;
        d1 = a%pow10[digit+1];
        d2 = b%pow10[digit+1];
        //cout << d1 << "," << d2 << endl;
        for(int i = last1; i < last2; i++) {
            for(mpz_class d = 0; d < 10; d++) {
//                cout << (pos[i] + pow10[digit]*d) << " ";
                if(((pos[i] + pow10[digit]*d)*d2)%pow10[digit+1] == d1) {
                    pos[z++] = pos[i] + pow10[digit]*d;
                    //cout << pos[z-1] << " ";
                }
            }
        }
        if(digit == nd(a)) break;
        last1 = last2;
        last2 = z;
    }

    mpz_class min = 9999999;
    int mini = z-1;
    for(int i = last1; i<last2; i++) {
        if(pos[i] < min) {
            min = pos[1];
            mini = i;
        }
    }
    return pos[mini];
}

int main(){
	init();
	//cout << endsWith(primes[np-2], primes[np-1]);
	mpz_class tot = 0;
	mpz_class tmp, tmp2;
	for(int i = 2; i < np-1; i++) {
		tmp = endsWith(primes[i], primes[i+1]);
		tot += tmp*primes[i+1];
		if(i%1000 == 0) cout << i << "/" << np << endl;
	}
	//cout << "done" << endl;
	cout << tot << endl;
    //cin.get();*/
    return 0;
}
