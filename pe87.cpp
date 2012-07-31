#include <iostream>
#include <fstream>

#include "util.h"

using namespace std;

bool canBe[50000000];

int main(){
    initialize();
    fori(50000000) canBe[i] = false;
    
    for(int i=0; primes[i]<85; i++){
        for(int j=0; primes[j] < 369 ;j++){
            for(int k=0; primes[k] < 7072; k++){
                if(primes[k]*primes[k]+primes[j]*primes[j]*primes[j]+primes[i]*primes[i]*primes[i]*primes[i] < 50000000) {
                    //cout << primes[i]*primes[i]+primes[j]*primes[j]*primes[j]+primes[k]*primes[k]*primes[k]*primes[k] << endl;
                    canBe[primes[k]*primes[k]+primes[j]*primes[j]*primes[j]+primes[i]*primes[i]*primes[i]*primes[i]] = true;
                }
            }
            
        }
        cout << i << endl;
    }
    int n = 0;
    fori(50000000)if(canBe[i]) n++;
    cout << n << endl;
    
    cin.get();
    return 0;   
}
