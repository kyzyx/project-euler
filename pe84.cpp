#include <iostream>
#include <cstdlib>
#include <ctime>
#define D 4
#define N 10000000

using namespace std;

int ch[] = {7, 22, 36};
int chDest[] = {0,10,11,24,39,5};
int cc[] = {2, 17, 33};
int u[] = {12, 28};

unsigned long freq[40];

int dieRoll(){
    return rand()%D+1;
}

int main(){
    srand(time(NULL));
    
    for(int i=0; i<40; i++) freq[i] = 0;
    
    int currpos = 0, die1, die2, ndoub = 0, chance=0, commchest=0;
    for(unsigned long i=0; i<N; i++){
        //if(i%100000==0) srand(time(NULL));
        die1 = dieRoll(); die2 = dieRoll();
        if(die1 == die2) ndoub++;
        else ndoub = 0;
        if(ndoub == 3){
             currpos = 10;
             freq[10]++;
             ndoub = 0;
        }
        else{
            currpos += die1 + die2;
            currpos %= 40;
            if(currpos == 30) currpos = 10;
            else if(currpos == ch[0] || currpos == ch[1] || currpos == ch[2]){ //Chance
                if(chance<5) currpos = chDest[chance];
                else if(chance < 7){
                    currpos = (((currpos+5)/10)*10+5)%40;
                }
                else if(chance < 9){
                    if(currpos>27 || currpos<12) currpos = u[0];
                    else currpos = u[1];
                }
                else if(chance == 9){
                    if(currpos == 36){ //draw community chest
                        if(commchest == 0) currpos = 0;
                        else if(commchest == 1) currpos = 10;
                        commchest = (commchest + 1)%16;
                    }
                    else currpos -= 3;
                }
                chance = (chance + 1)%16;
            }
            else if(currpos == cc[0] || currpos == cc[1] || currpos == cc[2]){ //Community Chest
                if(commchest == 0) currpos = 0;
                else if(commchest == 1) currpos = 10;
                commchest = (commchest + 1)%16;
            }
        }
        if(ndoub == 0) freq[currpos]++;
    }
    int max1= 0, max2 = 0;
    for(int i=0; i<40; i++){
        if(freq[i]>max1 && i!= 10) max1 = freq[i];
    }
    for(int i=0; i<40; i++){
        if(freq[i]>max2 && i!= 10 && freq[i] != max1) max2 = freq[i];
    }
    cout << "1: 10" << endl;
    for(int i=0; i<40;i++){
        if(freq[i] == max1) cout << "2: " << i << endl;
        else if(freq[i] == max2) cout << "3: " << i << endl;
    }
    
    cin.get();
    return 0;
}
