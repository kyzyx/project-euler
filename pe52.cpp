#include <iostream>
#include <fstream>
#include "util.h"

using namespace std;

int main(){
    for(int i=100; i<1000000; i++){
        if(isPerm(i,2*i) && isPerm(i,3*i)){
            if(isPerm(i,4*i) && isPerm(i,5*i)){
                if(isPerm(i,6*i)){
                    cout << i; break;
                }
            }
        }
        if(i%50000 == 0) cout << i << endl;
    }
    
    cin.get();
    return 0;   
}
