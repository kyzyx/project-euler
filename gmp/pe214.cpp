#include <iostream>
#include "util.h"
#include <gmp.h>
#include <gmpxx.h>
#define fori(N) for(int i=0; i<N; i++)
#define forj(N) for(int j=0; j<N; j++)
#define Fori(m,n) for(int i=m; i<n; i++)
#define N 40000000

using namespace std;
typedef mpz_class BigInt;

int totient[N+1];
int pfs[N+1];

void fillpfs(){
    Fori(0,N+1) pfs[i] = 0;
    Fori(2,N+1){
        if(isprime[i]){
            for(int j=0; j<N+1; j += i){
                pfs[j]++;
            }
            if(i <= 6325 && i*i < N+1)  pfs[i*i] = 0;
        }
    }
    Fori(2,N+1){
        if(pfs[i] == 0){
            for(int j=0; j<N+1; j+=i){
                pfs[j] = 0;
            }
        }
    }
}

void filltot(){
    Fori(0,N+1) totient[i] = i-1;
    Fori(2,N+1){
        if(pfs[i] == 0) continue;
        else if(pfs[i]%2){
            for(int j=0; j<N+1; j+=i){
                totient[j] -= j/i-1;
            }
        }
        else{
            for(int j=0; j<N+1; j+= i){
                totient[j] += j/i-1;
            }
        }
    }
}
int chainLength(long n){
    int i;
    long a = n;
    for(i=1; a > 1; i++){
        a = totient[a];
    }
    return i;
}

int main(){
    int max = 100;
    BigInt p;
    BigInt ulimit(40000001);
    
    initialize();
    BigInt lastprime(primes[numprimes-1]);
    mpz_nextprime(p.get_mpz_t(), lastprime.get_mpz_t());
    while(p<ulimit){
        isprime[p.get_si()] = true;
        primes[numprimes++] = p.get_si();
        mpz_nextprime(p.get_mpz_t(), p.get_mpz_t());
    }
    cout << "Done getting primes" << endl;
    fillpfs();
    filltot();
    
    unsigned long sum = 0;
    unsigned long nhm = 0;
    
    fori(numprimes){
        if(chainLength(primes[i]) == 25) {
            if(sum >= 100000000){
                sum -= 100000000;
                nhm++;
            }
            sum += primes[i];
        }
    }
    cout << nhm << "00000000 + " << sum << endl;
   // cin.get();
    return 0;
}
