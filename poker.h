#include <iostream>
#include <fstream>

#define fori(N) for(int i=0; i<N; i++)
#define max(a,b) a>b?a:b
using namespace std;

bool isFlush(char h[]){
    fori(5) if(h[i] != h[0]) return false;
    return true;
}

int isStraight(int h[]){
    if(h[4] == 14 && h[0] == 2){
        for(int i=0; i<4; i++){
            if(h[i] != i+2) return 0;
        }
        return 5;
    }
    else{
        fori(5){
            if(h[i] != i+h[0]) return 0;
        }
        return h[4];
    }
}

int numDup(int h[]){
    int dup = 1;
    int maxDup = 1;
    int val = h[4];
    for(int i=1; i<5; i++){
        if(h[i] == h[i-1]) dup++;
        if(maxDup <= dup){
            maxDup = dup;
            val = h[i-1];
        }
        
        if(h[i] != h[i-1]) dup = 1;
    }
    if(maxDup == 1) val = h[4];
    return maxDup*100+val;  //maxdup/100 = numDup; maxdup%100 = value
}

int isFullHouse(int h[]){
    int tmp = numDup(h);
    if(tmp/100 == 3){
        int n = 0;
        for(int i=0; i<5; i++){
            if(h[i] != tmp%100){
                if(n==0) n = h[i];
                else if(h[i] == n) return n; 
                else return 0;
            }
        }         
    }
    else{
         return 0;
    }
}
int isTwoPair(int h[]){
    int tmp = numDup(h);
    if(tmp/100 == 2){
        int p1=0;
        for(int i=0; i<4; i++){
            if(h[i] != tmp%100 && h[i] == h[i+1]){
                p1 = h[i++];
                break;
            }
        }
        return p1;
    }
    return 0;
}

void readHand(ifstream& in, int* h, char* c){
    char tmp;
    fori(5){
        tmp = in.get();
        switch(tmp){
            case 'A': h[i] = 14;
                    break;
            case 'T': h[i] = 10;
                    break;
            case 'J': h[i] = 11;
                    break;
            case 'Q': h[i] = 12;
                    break;
            case 'K': h[i] = 13;
                    break;
            default: h[i] = tmp-'0';
        }
        c[i] = in.get();
        in.get();
    }
    
}
