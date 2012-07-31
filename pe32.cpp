#include <iostream>
#include <fstream>
#include "util.h"

using namespace std;

int main(){
    string curr = "";
    char tmp[11];
    fori(9999) prod[i] = false;
    int sum = 0;
    
    for(int i=1; i<9999; i++){
        for(int j=i; j<9999; j++){
            if(i*j>9999 || prod[i*j]) continue;
            curr = itoa(i, tmp, 10);
            curr += itoa(j, tmp, 10); 
            curr += itoa(i*j, tmp, 10);
            if(isPD(atoi(curr.c_str()))){
                sum += i*j;
                prod[i*j] = true;           
            }
        }
        if(i%200 == 0) cout << i << endl;  
    }
    cout << sum << endl;
       
    cin.get();
    return 0;   
}
