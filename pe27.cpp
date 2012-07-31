#include <iostream>
#include <fstream>
#include "util.h"

using namespace std;

bool isprime[8000];
int primes[2000];

int numP(int b, int c){
    fori(500){
        if(!isprime[i*i+b*i+c]) return i-1;
    }
    return 1000;
}

int main(){
    int z = 0;
    fori(8000) isprime[i] = false;
    ifstream in("prime1m.txt");
    int curr;
    while(!in.eof()){
        in >> curr;
        if(curr>8000) break;
        isprime[curr] = true;
        primes[z++] = curr;
    }
    int a, tmp;
    long maxf = 0, pd = 0;

    for(int i=0; i<z && primes[i] <1000; i++){
        forj(z){
           a = primes[i]-primes[j] + 1;
           tmp = numP(a, primes[i]);
           if(tmp > maxf) {
                maxf = tmp;
                pd = a*primes[i];
            }
        }
    }
    cout << maxf << " " << pd << endl;
    cin.get();
    return 0;
}
