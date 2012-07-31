#include <iostream>
#include <fstream>
#include "util.h"

using namespace std;

int main(){
    int longest = 0, p = 0, sum = 0;
    fori(numprimes){
        sum = 0;
        for(int j=i; j<numprimes;j++){
             sum += primes[j];
             if(sum > 1e6) break;
             if(isprime[sum] && j-i>longest){
                longest = j-i;
                p = sum;   
             }
        }
    }
    cout << longest << " consecutive primes add up to " << p << endl;
    cin.get();
    return 0;   
}
