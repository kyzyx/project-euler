#include <iostream>
#include <fstream>
#include <vector>
#include "util.h"

using namespace std;

int main(){
    double targ = 3./7;
    double min = 1.;
    double tmp;
    
    unsigned long currNum = 2;
    unsigned long currDen = 5;
    
    for(unsigned long i=6; i<1000000; i++){
        for(unsigned long j=currNum; j<(i*3)/7+1; j++){
            tmp = double(j)/i;
            if(tmp >= targ) break;
            if(targ-tmp < min){
                 min = targ-tmp;
                 currNum = j;
                 currDen = i;
            }
        }
        if(i%10000 == 0) cout << i << endl;
    }
    
    cout << currNum << "/" << currDen << endl;
    
    cin.get();
    return 0;
}
