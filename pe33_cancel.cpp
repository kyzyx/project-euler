#include <iostream>
#include <fstream>
#include "util.h"

using namespace std;

double eps = 0.000001;

bool isCancel(int a, int b){
    double orig = (double(a))/b;
    //Cancel first digits
    if(a/10 == b/10 && abs(orig - (double(a%10))/(b%10)) < eps) return true;
    //cancel last digits
    if(a%10 == b%10 && abs(orig - (double(a/10))/(b/10)) < eps) return true;
    //cancel f/l
    if(a%10 == b/10 && abs(orig - (double(a/10))/(b%10)) < eps) return true;
    //cancel l/f
    if(a/10 == b%10 && abs(orig - (double(a%10))/(b/10)) < eps) return true;
    return false;
}

int main(){
    for(int i=10; i<100; i++){
        for(int j=i+1; j<100; j++){
            if(i%10==0 && j%10==0) continue;
            if(isCancel(i,j)) cout << i << "/" << j << endl;
        }
    }
    cin.get();
    return 0;   
}
