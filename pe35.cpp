#include <iostream>
#include <fstream>
#include "util.h"

using namespace std;

int nextCircle(int n){
    int om = pow(10, numdigs(n)-1);
    if(n%om < om/10) return -1;
    n = (n%om)*10 + n/om;
    return n;
}

int main(){
    initialize();
    int n = 0, curr;
    bool circ = true;

    fori(numprimes){
        if(primes[i] > 1000000) break;
        circ = true;
        curr = primes[i];
        forj(numdigs(curr)-1){
            curr = nextCircle(curr);
            if(curr<0 || !isprime[curr]){
                 circ = false; break;
            }
        }
        if(circ){
             cout << primes[i] << endl;
             n++;
        }
    }
    cout << n;
    cin.get();
    return 0;   
}
