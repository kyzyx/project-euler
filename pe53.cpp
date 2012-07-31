#include <iostream>

using namespace std;

bool works(int a, int b) {
    double ret = 1;
    for(int i = 0; i < b; ++i) {
        ret *= a-i;
        ret /= i+1;
        if (ret > 1000000) return true;
    }
    return false;
}

int main() {
    int t = 0;
    for(int i = 0; i < 101; ++i) {
        for(int j = 0; j <= i/2; ++j) {
            if (works(i,j)) {
                t += (i+1) - 2*j;
                break;
            }
        }
    }
    
    cout << t << endl;
    
    cin.get();
    return 0;
}
