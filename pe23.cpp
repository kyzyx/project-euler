#include <iostream>
#include <fstream>
#include "util.h"

using namespace std;
//Factors
int apd(int n){
    int t = 0;
    for(int i=1; i<=n/2; i++){
        if(n%i == 0) t+=i;
    }
    return t-n;
}
int main(){

    int abundant[15000];
    int z = 0;
    fori(28130){
        if(apd(i) > 0){
            abundant[z++] = i;
        }
    }
    cout << "Calculated " << z << " Abundant Numbers" << endl;
    
    bool sat[28130];
    fori(28130) sat[i] = false;
    
    fori(z){
        for(int j=i; j<z; j++){
            if(abundant[i]+abundant[j] < 28130)
                sat[abundant[i]+abundant[j]] = true;
        }
    }
    
    unsigned long tot = 0;
    fori(28130) if(!sat[i]) tot += i;
    cout << tot;
    
    cin.get();
    return 0;   
}
