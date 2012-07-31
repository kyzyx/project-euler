#include <iostream>
#include <fstream>
#include "util.h"
#define Fori(m,n) for(int i=m; i<n; i++)
#define N 12000

using namespace std;

int totient[N+1];
int pfs[N+1];

void fillpfs(){
    Fori(0,N+1) pfs[i] = 0;
    Fori(2,N+1){
        if(isprime[i]){
            for(int j=0; j<N+1; j += i){
                pfs[j]++;
            }
            if(i <= 110 && i*i < N+1)  pfs[i*i] = 0;
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
void fill3tot(){
    Fori(0,N+1) totient[i] = i/3;
    Fori(2,N+1){
        if(pfs[i] == 0) continue;
        else if(pfs[i]%2){
            for(int j=0; j<N+1; j+=i){
                for(int k=i; k<=j/3; k+=i)
                    totient[j] -= 1;
            }
        }
        else{
            for(int j=0; j<N+1; j+= i){
                for(int k=i; k<=j/3; k += i)
                    totient[j] += 1;
            }
        }
    }
}

int main(){
    initialize();
    cout << "Done getting primes " << primes[numprimes-1] << endl;
    fillpfs();
    cout << "Done filling primefactors" << endl;
    filltot();
    cout << "Done Generating totients" << endl;
    
    unsigned long sum = 0;
    for(int i=2; i<N+1; i++) sum += totient[i];
    cout << (sum-1)/2 << endl;
    
    unsigned long s3 = 0;
    fill3tot();
    for(int i=2; i<N+1; i++) {
        //cout << i << " " << totient[i] << endl;
        s3 += totient[i];
    }
    cout << s3 << endl;
    cout << (sum-1)/2 - s3 << endl;
    
    cin.get();
    return 0;
}
