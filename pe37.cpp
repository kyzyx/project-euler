#include <iostream>
#include <fstream>
#include "util.h"

using namespace std;

int main(){
    initialize();
    bool truncatable = true;
    int n, mod, t=0;
    fori(numprimes){
        if(primes[i]<10) continue;
        n = primes[i];
        while(n>0){
            if(!isprime[n]){
                 truncatable = false;
                 break;
            }
            n/=10;
        }
        n = primes[i];
        mod = pow(10,log10(n)-1);
        
        while(mod > 1){
            if(!isprime[n%mod]){
                truncatable = false;
                break;
            }
            mod/=10;
        }
        if(truncatable) t += primes[i];
        truncatable = true;
    }
    cout << t;
    cin.get();
    return 0;   
}
