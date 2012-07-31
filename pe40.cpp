#include <iostream>
#include <fstream>
#include "util.h"

using namespace std;

int main(){
    int n = 0;
    int prod = 1;
    bool done[4];
    fori(4) done[i] = false;
    int i;
    for(i=1; n<=1000000; i++){
        n += log10(i);
        if(n==10 || n==11) cout << n << " " << i << endl;
        if(!done[0] && n>=100){
             cout << n << " " << i << endl;
             done[0] = true;
        }
        if(!done[1] && n>=1000){
             cout << n << " " << i << endl;
             done[1] = true;
        }
        if(!done[2] && n>=10000){
             cout << n << " " << i << endl;
             done[2] = true;
        }
        if(!done[3] && n>=100000){
             cout << n << " " << i << endl;
             done[3] = true;
        }
    }
    cout << n << " " << i << endl;
    cin.get();
    return 0;
}
