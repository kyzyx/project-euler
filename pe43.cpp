#include <iostream>
#include <fstream>
#include "util.h"

using namespace std;

unsigned long long tos(char* n, int s, int e){
    unsigned long long r = 0;
    for(int i=s-1; i<e; i++){
        r *= 10;
        r += n[i]-'0';
        
    }
    return r;
}

int main(){
    char n[11] = "0123456789";
    unsigned long long sum = 0;
    int z=0;
    unsigned long i;
    for(i=0; next_permutation(n, n+10); i++){
        
        if(n[0] == '0') continue;
        
        if(tos(n,2,4)%2 == 0 && tos(n,3,5)%3 == 0 && tos(n,4,6)%5 == 0){
              if(tos(n,5,7)%7 == 0 && tos(n,6,8)%11 == 0 && tos(n,7,9)%13 == 0){
                    if(tos(n,8,10)%17 == 0){
                         sum += tos(n, 1, 10);
                         
                    }
                }
        }
        
    }
    cout << sum;
    cin.get();
    return 0;   
}
