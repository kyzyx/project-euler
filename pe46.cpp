#include <iostream>
#include <fstream>

#include "util.h"

using namespace std;

bool canbe[100000];

int main(){
    initialize();
    fori(100000) canbe[i] = false;
    canbe[1] = true;
    fori(1000){
        forj(1000){
            if(primes[i] + 2*j*j < 100000)
                canbe[primes[i] + 2*j*j] = true;
        }
    }
    
    for(int i=1; i<100000; i+=2){
        if(isprime[i]) continue;
        if(!canbe[i]){
            cout << i;
            break;
        }
    }
    cin.get();
    return 0;   
}
