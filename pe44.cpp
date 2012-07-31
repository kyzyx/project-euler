#include <iostream>
#include <fstream>
#include "util.h"

using namespace std;

bool pent[30000000];
unsigned long pnum[1000000];
unsigned long tria[1000000];

int main(){
    //ifstream fin("C-large.in");
    //ofstream fout("C-large.out");
    /*int numdiv;
    long n = 1;
    for(int i=2; i<100000; i++){
        tria[i] = tri(i);    
    }
    cout << "Got tri" << endl;
    cin.get();
    for(int i=2; i<100000; i++){
        if(numfac(tri[i]) >= 500){
             cout << i << ":" << numfac(tri(i)) << endl;
             break;
        }
        if(i%1000 == 0) cout << i << endl;
        //if(i>9980)  cout << i << ":" << numfac(tri(i)) << endl;
    }*/
    unsigned long bestD = 999999999;
    //unsigned long n;
    for(int n=0; n<2583; n++){
         pnum[n] = (n*(3*n-1))/2;
         pent[(n*(3*n-1))/2] = true;
    }
    for(int i=1; i<2583; i++){
        for(int j=i+1; j<2583; j++){
            if(pent[pnum[j]-pnum[i]] && pent[pnum[i] + pnum[j]] && pnum[j]-pnum[i] < bestD){
                 cout << "P(" << j << " " << i << ": " << pnum[j] << "," << pnum[i] << endl;
                 bestD = pnum[j]-pnum[i];
            }
        }
    }
    cout << bestD << endl;
    cin.get();
    return 0;   
}
