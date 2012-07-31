#include <iostream>
#include <fstream>

#include "util.h"

using namespace std;

bool isIncreasing(unsigned long n){
    unsigned int lastd = n%10;
    while(n>0){
        n/=10;
        if(lastd < n%10) return false;
        lastd = n%10;
    }
    return true;
}
bool isDecreasing(unsigned long n){
    unsigned int lastd = n%10;
    while(n>10){
        n/=10;
        //cout << n%10 << lastd << endl;
        if(lastd > n%10) return false;
        
        lastd = n%10;
    }
    return true;
}


int main(){
    unsigned long n=0;//if(isDecreasing(6421)) cout << "Yay" << endl;
    for(unsigned long long i = 100; i<999999999; i++){
        if(!isDecreasing(i) && !isIncreasing(i)) n++;
        if(100*(i-n) == i){
             cout << i << endl;
             break;
        }
        if(i%10000000 == 0) cout << i << endl;
    }
    
    cin.get();
    return 0;   
}
