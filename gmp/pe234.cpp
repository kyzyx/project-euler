#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
//#define MAX 1000
#define fori(n) for(int i=0; i<n; i++)

typedef mpz_class BigInt;
using namespace std;

int primes[1000000];
int np = 0;

void init(){
    bool isprime[1000004];
    fori(1000004) isprime[i] = true;
    for(int i=2; i<1000004; i++){
        if(isprime[i]){
            for(int j=2*i; j<1000004; j+=i){
                isprime[j] = false;
            }
            primes[np++] = i;
        }
    }
}

int main(){
    init();

    BigInt a,b;
    BigInt n = 0;
    BigInt sum = 0;
    BigInt j;
	BigInt MAX("999966663333");

    for(int i=0; i<np-1; i++){
        a = primes[i];
        b = primes[i+1];

        for(j=a*(a+1); j<MAX && j<b*b; j+=a){
            if(j%b != 0){
                ++n;
                sum += j;
            }
        }
        for(j=(a*a/b + 1)*b; j<MAX && j<b*b; j+=b){
            if(j%a!=0){
                ++n;
                sum += j;
            }
        }
        //cout << b << endl;
    }

    cout << n << ":" << sum << endl;
    cin.get();
    return 0;
}
