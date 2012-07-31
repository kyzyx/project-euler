#include <iostream>
#include <fstream>
#include "util.h"
using namespace std;

int nf[10000000];

int main(){
    fori(10000000) {
        if(i%2 == 0) nf[i] = 2;
        else nf[i] = 1;
    }
    for(int i=3; i< 10000000; i++){
        for(int j=i; j<10000000; j+=i){
            nf[j]++;
        }
        if(i%500000 == 0) cout << i << endl;
    }
    cout << "done factors" << endl;
    int prev = nf[2];
    int n = 0;
    for(int i=3; i<10000000; i++){
        if(prev == nf[i]) n++;
        prev = nf[i];
    }
    cout << n << endl;
    cin.get();
    return 0;   
}
