#include <iostream>
#include <iomanip>
#define EPS 1e-11

using namespace std;

double prob[51][21];

double calcProb(double q) {
    for(int i = 0; i < 50; i++) {
        for(int j = 0; j < 21; j++) {
            prob[i][j] = 0;
        }
    }
    prob[0][0] = 1/q;
    prob[0][1] = (q - 1)/q;
    for(int i = 1; i < 50; i++) {
        prob[i][0] = prob[i-1][0]*(i+1)/q;
        for(int j = 1; j < 21; j++) {
            prob[i][j] = prob[i-1][j]*(i+1)/q + prob[i-1][j-1]*(q - i - 1)/q;
        }
    }
    return prob[49][20];
}

int main() {
    double target = 0.02;
    
    double lo = 50, hi = 60;
    double mid;
    
    while (hi - lo > EPS) {
        mid = (lo + hi) / 2; 
        
        double p = calcProb(mid);
        cout << mid << ": " << p << endl;
        if (p > target) {
            lo = mid;
        }
        else if (p < target) {
            hi = mid;
        }
        else break;
    }   
    cout << setprecision(12) << mid << endl;
    cin.get();
    return 0;
}
