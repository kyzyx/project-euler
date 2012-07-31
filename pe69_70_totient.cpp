#include <iostream>
#include <fstream>
#include "util.h"
#define Fori(m,n) for(int i=m; i<n; i++)
#define N 10000000

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
            if(i <= 3170 && i*i < N+1)  pfs[i*i] = 0;
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

int main(){
    initialize();
    cout << "Done getting primes " << primes[numprimes-1] << endl;
    fillpfs();
    cout << "Done filling primefactors" << endl;
    filltot();
    cout << "Done Generating totients" << endl;
    
    double tmp;
    
    //PE69  
    double max = 0.0;
    int nmax = 0;
    Fori(2,1000000){
        tmp = double(i)/totient[i]; 
        if(tmp > max){
             
             max = tmp;
             nmax = i;
        }
    }
    cout << nmax << ":" << max <<endl;/*
    //PE70
    double min = 1e8;
    int nmin = -1;
    Fori(10,N+1){
        tmp = double(i)/totient[i];
        if(isPerm(i, totient[i]) && tmp < min){
            min = tmp;
            nmin = i;
        }  
    }
    if(isPerm(87109, totient[87109]))cout << totient[87109] << endl;
    if(nmin == -1) cout << "crap" << endl;
    else cout << nmin << " = " << totient[nmin] << ":" << min << endl;
    //PE72
    unsigned long sum = 0;
    int numHMills = 0;
    Fori(2,N+1){
         sum += totient[i];
         if(sum > 100000000){
                 numHMills++;
                sum -= 100000000;
         }
    }
    cout << numHMills << "00000000 + " << sum << endl;*/
    
    cin.get();
    return 0;
}
