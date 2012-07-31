#include <iostream>

using namespace std;

int vals[] = {1,2,4,8,16,32,64,128,256,512};

bool canDoNum(int die1, int die2, int v1, int v2){
    if((die1 & vals[v1]) && (die2 & vals[v2]) || (die1 & vals[v2]) && (die2 & vals[v1])) return true;
    else return false;
}

bool canDo(int die1, int die2){
    if(!canDoNum(die1, die2, 0, 1)) return false;
    if(!canDoNum(die1, die2, 0, 4)) return false;
    if(!canDoNum(die1, die2, 0, 9) && !canDoNum(die1, die2, 0, 6)) return false;
    if(!canDoNum(die1, die2, 1, 6) && !canDoNum(die1, die2, 1, 9)) return false;
    if(!canDoNum(die1, die2, 2, 5)) return false;
    if(!canDoNum(die1, die2, 3, 6) && !canDoNum(die1, die2, 3, 9)) return false;
    if(!canDoNum(die1, die2, 4, 9) && !canDoNum(die1, die2, 4, 6)) return false;
    if(!canDoNum(die1, die2, 8, 1)) return false;

    return true;
}

bool count1(int n){
    int t = 0;
    for(int i=0; i<10; i++){
        if(n&vals[i]) t++;
    }
    if(t!=6) return false;
    return true;
}

int main(){
    unsigned long tot = 0;
    //if(canDo(994,798)) cout << "Huzzah!" << endl;
    
    for(int i=63; i<1023; i++){
        if(count1(i)){
            for(int j=63; j<1023; j++){
                if(count1(j)){
                    if(canDo(i,j)) ++tot;
                }
            }
        }
    }  
    
    cout << tot/2 << endl;
    cin.get();
    return 0;
}
