#include <iostream>
#include <fstream>
#include "util.h"

using namespace std;

char message[2000];
int z;

int countthes(char txt[]){
    int ret = 0;
    fori(z-3){
        if(txt[i] == 't' && txt[i+1] == 'h'&& txt[i+2] == 'e') ret++;
    }
    return ret;
}
long sumAscii(char t[]){
    long sum = 0;
    fori(z){
        sum += t[i];
    }
    return sum;
}
int decrypt(char a, char b, char c, int show){
    char chs[3] = {a, b, c};
    char dec[z];
    int n = 0;
    for(int i=0, n=0; i<z; i++){
        dec[i] = message[i]^chs[n];
        if(show == 1) cout << dec[i];
        n++;
        n%=3;
    }
    if(show == 2) return sumAscii(dec);
    else return countthes(dec);
}



int main(){
    z = 0;
    int tmp;
    ifstream in("cipher1.txt");
    in >> tmp;
    message[z++] = (char) tmp;
    while(!in.eof()){
        in.get();
        in >> tmp;
        message[z++] = (char) tmp;
        
    }
    cout << "done reading" << endl;
    int maxthe = 0;
    char best[4];
    best[3] = '\0'; 
    for(char a='a'; a<='z';a++){
        for(char b='a'; b<='z';b++){
            for(char c='a'; c<='z';c++){
                if(maxthe < decrypt(a, b, c, 0)){
                    maxthe = decrypt(a, b, c, 0);
                    best[0] = a;
                    best[1] = b;
                    best[2] = c;
                }
                
            }
        }
    }
    
    cout << best << endl;
    decrypt(best[0], best[1], best[2], 1);
    
    cout << endl << "--" << decrypt(best[0], best[1], best[2], 2);
    
    cin.get();
    return 0;   
}
