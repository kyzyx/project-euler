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

bool isLychrel(int n){
    unsigned long long a = n;
    fori(50){
        a = a+reverse(a);
        if(isPal(a)) return false;
        //cout << a << endl;
    }
    return true;
}

int main(){
    //if(isLychrel(196)) cout << "good" << endl;
    int numL = 0;
    for(int i=10; i<10000; i++){
        if(isLychrel(i)){
             numL = numL + 1;
            cout << "got one" << i << endl;
        }
//        if(i%1000 == 0) cout << i << endl;
    }
    cout << numL << endl;
    
    cin.get();
    return 0;   
}
