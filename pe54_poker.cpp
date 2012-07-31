#include "poker.h"

int* rank(int h[], char c[]){
    int* ret = new int[6];
    fori(6) ret[i] = 0;
    if(isFlush(c)) {
        if(isStraight(h)){
             ret[0] = 8;
             ret[1] = isStraight(h);
        }
        else{
             ret[0] = 5;
             fori(5){
                ret[1+i] = h[4-i];
             }
        }
    }
    else if(isStraight(h)){
         ret[0] = 4;
         ret[1] = isStraight(h);
    }
    else{
        if(isFullHouse(h)){
            ret[0] = 6;
            ret[1] = numDup(h)%100; //value of trip
            for(int i=0; i<5; i++) {
                if(h[i] != ret[1]){
                     ret[2] = h[i];
                     break;
                }
            }
        }
        else if(isTwoPair(h)){
            ret[0] = 2;
            ret[1] = numDup(h)%100;//val of high dup
            ret[2] = isTwoPair(h);//val of low dup
            for(int i=0; i<5; i++) {
                if(h[i] != ret[1] && h[i] != ret[2]){
                     ret[3] = h[i];
                     break;
                }
            }
        }
        else{
            int tmp = numDup(h);
            switch(tmp/100){
                case 1: ret[0] = 0;
                    break;
                case 2: ret[0] = 1;
                    break;
                case 3: ret[0] = 3;
                    break;
                case 4: ret[0] = 7;
                    break;
            }
            ret[1] = tmp%100;
            int z = 2;
            for(int i=4; i>=0; i--){
                if(h[i] == ret[1]) continue;
                ret[z++] = h[i]; 
            }
        }
    }
    
    return ret;
}

int win1(int r1[], int r2[]){
    fori(6) {
        if(r1[i] > r2[i]) return 1;
        else if(r1[i] < r2[i]) return 0;
    }
    return 0;
}

int main(){
    int numWins = 0;
    ifstream in("poker.txt");
    fori(1000){
        //read hand
        int h1[5], h2[5];
        char c1[5], c2[5];
        readHand(in, h1, c1);
        readHand(in, h2, c2);
        
        //sort
        sort(h1, h1+5);
        sort(h2, h2+5);
        
        /*for(int k=0; k<5; k++){
            cout << h1[k] << c1[k] << " ";
        }
        cout << "\t";
        for(int k=0; k<5; k++){
            cout << h2[k] << c2[k] << " ";
        }
        cout << endl;*/
        //rank      
        cout << i << " ";
        numWins += win1(rank(h1, c1), rank(h2, c2));
    }
    
    cout << numWins << endl;
    cin.get();
    return 0;
}   
