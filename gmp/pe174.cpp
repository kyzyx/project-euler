#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#define fori(N) for(int i=0; i<N; i++)
#define forj(N) for(int j=0; j<N; j++)

using namespace std;
typedef mpz_class BigInt;

int main(){
    long max = 1000000;
    long u;
    BigInt n(max);
    BigInt ti(0);
    BigInt tj(0);
    BigInt ti2(0);
    BigInt tmp(0);
    
    short numLam[max+1];
    fori(max+1) numLam[i] = 0;
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
                numLam[tmp.get_ui()]++;
            }
            else{
                if(i*i-j*j > max) break;
                numLam[i*i-j*j]++;
            }
        }
        if(i%20000==0) cout << i << endl;
    }
    
    int* t = new int[max];
    fori(max+1) {
        if(numLam[i] > 20) continue;
        t[numLam[i]]++;
        if(i%10000==0) cout << i << endl;
    }
    int total = 0;
    fori(16){
         if(i>0 && i<11) total += t[i];
         cout << i << ":" << t[i] << endl;
    }
    cout << "Total number is " << total << endl;
    

    return 0;
}
