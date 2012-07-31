#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#define N 10000000

using namespace std;

bool isprime[N];

unsigned long divmult(unsigned long p){
    for(int i=1; i<=10; i++){
        if(p*i%10 == 9) return (p*i+1)/10;
    }
}

int main(){
    mpz_class tot = 0;
    unsigned long n;
    for(unsigned long i=0; i<N; i++) isprime[i] = true;
    for(unsigned long i=2; i<N; ++i){
        if(isprime[i]){
            for(int j=2*i; j<N; j+=i){
                isprime[j] = false;
            }
            if(i!=2 && i!=5){
                n = divmult(i);
                //cout << i << n << endl;
                tot += n;
            }
        }
    }

    cout << "Total is " << tot << endl;
    cin.get();
    return 0;
}
