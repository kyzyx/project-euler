#include <iostream>
#include <fstream>
#include "util.h"

using namespace std;


int main(){
    string curr = "";
    char tmp[11];
    int m = 0;
    int j;
    for(int i=1; i<9999; i++){
        curr = "";
        for(j=1; j<9; j++){
            curr += itoa(i*j, tmp, 10);
            if(curr.length() == 9) break;
        }  
        if(isPD(atoi(curr.c_str()))){
             if(i<100) cout << curr << " from " << i << "," << j << endl;
             m = max(m, atoi(curr.c_str()));   
        }
        if(i%500 == 0) cout << i << endl;  
    }
    cout << m << endl;
    cin.get();
    return 0;   
}
