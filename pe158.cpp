#include <iostream>

using namespace std;

unsigned long long choose(int n, int k) {
    if (k > n/2) k = n - k;
    double ret = 1;
    for(int i = 0; i < k; i++) {
        ret *= n - i;
        ret /= i+1;
    }
    return (int) ret;
}
long long pows[27];

int main() {
    pows[0] = 1;
    for(int i = 1; i < 27; i++) {
        pows[i] = pows[i-1]*2;
    }    
    /*for(int i = 26; i >= 0; i--) {
        pows[i] = pows[i-1] - i - 2;
    }*/
    unsigned long long max = 0;
    for(int i = 0; i < 26; i++) {
        unsigned long long c = choose(26, i+1);
        unsigned long long curr = c*(pows[i+1] - i - 2);
        cout << c << "*" << pows[i+1] - i - 2<< ":" <<  curr << endl;
        if (curr > max) max = curr;
    }
    cout << "Max: " << max << endl;
    cin.get();
    return 0;
}



