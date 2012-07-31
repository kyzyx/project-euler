#include <iostream>
#include <fstream>

#include "util.h"

using namespace std;

unsigned long long reverse(unsigned long long n){
    unsigned long long a = 0;
    while(n>0){
        a*= 10;
        a += n%10;
        n/=10;
    }
    return a;
}


int main(){
    initialize();
    int n=0;
    for(unsigned long long i=1; i<1000000000; i++){
        if(i%50000000 == 0) cout << i << endl;
        if(i%10 == 0) continue;
        if(dodigit(i+reverse(i))){
             //cout << i << "+" << reverse(i) << "=" << i+reverse(i) << endl; 
             n++;
        }
    } 
    cout << n << endl;
    
    cin.get();
    return 0;   
}
