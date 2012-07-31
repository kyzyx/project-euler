#include <iostream>
#include <fstream>
#include "util.h"

using namespace std;

int main(){
    double currpow[10];
    fori(10) currpow[i] = 1;
    int n = 0;
    fori(10000){
        for(int j=1; j<10; j++){
            currpow[j] *= j;
            if(numdigs(currpow[j]) == i+1){
                cout << currpow[j] << " " << ++n << endl;
            }
        }
    }
    cout << n;
    cin.get();
    return 0;   
}
