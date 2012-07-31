#include <iostream>

using namespace std;

int facs[10];

bool works(int n) {
    int tot = 0;;
    int m = n;
    while(m > 0) {
        tot += facs[m%10];
        m /= 10;
    }
    return tot == n;
}


int main() {
    facs[0] = 1;
    for(int i = 1; i < 10; ++i) facs[i] = i*facs[i-1];
    int tot = 0;
    for(int i = 10; i < 10000000; ++i) {
        if (works(i)) tot += i;
    }
    cout << tot << endl;
    
    cin.get();
    return 0;
}
