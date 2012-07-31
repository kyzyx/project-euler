#include <iostream>
#define L 40

using namespace std;

int main() {
    unsigned long long poss[L][10];
    poss[0][0] = 0;
    for(int i = 1; i < 10; i++) poss[0][i] = 1;
    unsigned long long tot = 9;
    // All step numbers
    for(int i = 1; i < L; i++) {
        poss[i][0] = poss[i-1][1];
//        cout << poss[i][0] << " ";
        for(int j = 1; j < 9; j++) {
            poss[i][j] = poss[i-1][j-1] + poss[i-1][j+1];
//            cout << poss[i][j] << " ";
        }
        poss[i][9] = poss[i-1][8];
//        cout << poss[i][9] << endl;
        for(int j = 0; j < 10; j++) {
            tot += poss[i][j];
        }
    }
    
    cout << tot << endl;
    
    // Step numbers from 0-8
    tot -= 8;
    for(int i = 1; i < L; i++) {
        poss[i][0] = poss[i-1][1];
        for(int j = 1; j < 8; j++) {
            poss[i][j] = poss[i-1][j-1] + poss[i-1][j+1];
        }
        poss[i][8] = poss[i-1][7];
        for(int j = 0; j < 9; j++) {
            tot -= poss[i][j];
        }
    }
    
    // Step numbers from 1-9
    tot -= 8;
    for(int i = 1; i < L; i++) {
        poss[i][1] = poss[i-1][2];
        for(int j = 2; j < 9; j++) {
            poss[i][j] = poss[i-1][j-1] + poss[i-1][j+1];
        }
        poss[i][9] = poss[i-1][8];
        for(int j = 1; j < 10; j++) {
            tot -= poss[i][j];
        }
    }
    
    // step numbers from 1-8
    tot += 7;
    for(int i = 1; i < L; i++) {
        poss[i][1] = poss[i-1][2];
        for(int j = 2; j < 8; j++) {
            poss[i][j] = poss[i-1][j-1] + poss[i-1][j+1];
        }
        poss[i][8]= poss[i-1][7];
        for(int j = 1; j < 9; j++) {
            tot += poss[i][j];
        }
    }
  
    cout << tot << endl;  
    cin.get();
    return 0;
}
