#include <iostream>
#include <fstream>
#include <ios>
#include "util.h"

using namespace std;

unsigned long probs[7][37];
double p4[37];
double p6[37];

void populate(int sides, int tot, int n){
    if(n == 0){
         ++probs[sides][tot];
    }
    else{
        for(int i=1; i<=sides; i++){
            populate(sides, tot+i, n-1);
        }
    }
}

int main(){
    fori(37){
        probs[4][i] = 0;
        probs[6][i] = 0;
    }
    populate(4, 0, 9);
    populate(6, 0, 6);
    unsigned long t4=0, t6=0;
    fori(37){
        t4 += probs[4][i];
        t6 += probs[6][i];
    }
    fori(37){
        p4[i] = (double)probs[4][i]/t4;
        p6[i] = (double)probs[6][i]/t6;
    }
    
    double pp = 0;
    
    fori(37){
        for(int j=i+1; j<37; j++){
            pp += p4[j]*p6[i];
        }
    }
    //cout.setf(0,ios::floatfield);
    cout.precision(8);
    cout << pp << endl;
    
    cin.get();
    return 0;   
}
