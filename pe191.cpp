#include <iostream>
#define L 30

using namespace std;

unsigned long genString(int nA, int nL, int l){
    unsigned long t = 0;;
    if(l==L) return 1;
    else{
        if(nA != 2){
            t+=genString(nA+1,nL,l+1);
        }
        if(nL == 0){
            t+=genString(0,nL+1,l+1);
        }
        t += genString(0, nL, l+1);
    }
    return t;
}

int main(){
    cout << genString(0,0,0) << endl;
    
    cin.get();
    return 0;
}
