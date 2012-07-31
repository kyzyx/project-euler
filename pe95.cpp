#include <iostream>
#include <fstream>
#include "util.h"
#define N 1000000

using namespace std;
int* sumdiv = new int[N+1];
int* lenChain = new int[N+1];

//Factors
void fillspd(){
    for(int i=2; i<N+1; i++){
        for(int j=i*2; j<N+1; j+=i){
            sumdiv[j] += i;
        }
    }
}

bool lengthChain(int n){
    unsigned long chain[50000];
    chain[0] = n;
    int z = 1;
    int j;
    unsigned long num = n;
    for(j=0; j<50000; j++){
        num = sumdiv[num];
        if(num > N) break;
        fori(z){
            if(chain[i] == num){
                 lenChain[num] = j+1 - i;
                 if(lenChain[num] == 28){
                    int min = N;
                    for(int k=0; k<z; k++){
                        if(chain[k] < min) min = chain[k];
                    }
                    cout << min << endl;
                    return true;
                 }
                 return false;
            }
        }
        chain[z++] = num;
    }
    return false;
    //return j; 
}

int main(){
    fori(N+1){
         sumdiv[i] = 1;
         lenChain[i] = 0;
    }
    fillspd();
    
    unsigned long maxl = 0;
    for(int i=2; i<N; i++){
        if(lenChain[i] == 0) lengthChain(i);
        if(lenChain[i] > maxl) maxl = lenChain[i];
        if(i%50000 == 0) cout << i << endl;
    }
    cout << "Max Length " << maxl << endl;
    
    cin.get();
    return 0;   
}
