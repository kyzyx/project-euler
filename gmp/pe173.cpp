#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#define fori(N) for(int i=0; i<N; i++)
#define forj(N) for(int j=0; j<N; j++)

using namespace std;
typedef mpz_class BigInt;

int main(){
    int max = 1000000;
    BigInt n(max);
    BigInt ti(0);
    BigInt tj(0);
    BigInt ti2(0);
    BigInt tmp(0);
    
    unsigned long numLam = 0;
    for(int i=3; i<max/4+2; i++){
        if(i>9999){
            ti = i;
            ti2 = ti*ti; 
        }
        for(int j=i-2; j>=2-(i%2); j-=2){
            if(i > 9999){
                tj = j;
                tmp = ti2 - (tj*tj);
                if(tmp> n) break;
                numLam++;
            }
            else{
                if(i*i-j*j > max) break;
                numLam++;
            }
        }
        if(i%10000 == 0) cout << i << endl;
    }
    
    cout << numLam << endl;
    
   // cin.get();
    return 0;
}
