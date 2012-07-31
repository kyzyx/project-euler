#include <iostream>
#include <fstream>
#include <vector>
#include "util.h"
#define Fori(m,n) for(int i=m; i<n; i++)
#define N 100000

using namespace std;

struct r{
    int n;
    int rad;
};

r rad[N+1];



bool cmp(r a, r b){
    if(a.rad == b.rad) return a.n < b.n;
    return a.rad < b.rad;
}

void fillrad(){
    Fori(0,N+1){
         rad[i].n = i;
         rad[i].rad = 1;
    }
    Fori(2,N+1){
        if(isprime[i]){
            for(int j=i; j<N+1; j += i){
                rad[j].rad *= i;
            }
        }
    }
}

int main(){
    initialize();
    fillrad();
    sort(rad+1, rad+N+1, cmp); 
    
    //Fori(1,50) cout << rad[i].n << " " << rad[i].rad << endl;
    //cout << rad[1].n << " " << rad[1].rad << endl; 
    //cout << rad[9999].n <<" " <<  rad[9999].rad;
    cout << rad[10000].n <<" " <<  rad[10000].rad;
    //cout << rad[10001].n <<" " <<  rad[10001].rad;
    
    cin.get();
    return 0;
}
