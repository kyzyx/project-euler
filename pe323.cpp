#include <iostream>
#include <cstdio>
#define MAX 80
#define MM 33

using namespace std;

double probs[MAX][MM];

double ncr[MM][MM];
double pow2[MM];

double init(int n, int k) {
    double ret = 1;
    if (k > n/2) k = n - k;
    for(int i = 0; i < k; i++) {
        ret *= n - i;
        ret /= i+1;    
    }
    return ret;
}

int main() {
    double prob = 1;
    for(int i = 0; i < MM; i++) {
        pow2[i] = prob;
        prob *= 2;
    }
    
    for(int i = 0; i < MM; i++) {
        for(int j = 0; j < MM; j++) {
            ncr[i][j] = init(i, j);
        }
    }
    
    for(int i = 0; i < MM; i++) {
        probs[0][i] = ncr[MM-1][i]/pow2[MM-1];
        //cout << "0 " << i << ": " << probs[0][i] << endl;
    }
    
    double tot = probs[0][MM-1];
    double tp = probs[0][MM-1];
    for(int i = 1; i < MAX; i++) {
        for(int j = 0; j < MM; j++) {
            probs[i][j] = 0;
        }
        
           
        for(int j = 0; j < MM; j++) {
            for(int k = 0; k < MM - j; k++) {
                
                probs[i][j+k] += probs[i-1][j] * ncr[MM-1-j][k]/pow2[MM-1-j];              
                //cout << j << "+" << k << 
//              probs[i][j+k] += probs[i-1][j] + ncr[32-j][k]/pow2[32-j];
            }
        }
        
        
        /*for(int j = 0; j < MM; j++) {
            cout << i << " " << j << ": " << probs[i][j] << endl;
        }*/
        tot += (probs[i][MM-1] - probs[i-1][MM-1])*(i+1);
        tp += (probs[i][MM-1] - probs[i-1][MM-1]);
        /*cout << i << ": " << (probs[i][MM-1] - probs[i-1][MM-1]) << endl;
        cin.get();*/
    }
    printf("Total probability is %.11f\n", tot/tp);
    cin.get();
    return 0;
}
