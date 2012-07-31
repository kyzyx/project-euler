#include <iostream>

using namespace std;

int digits(int n, int b) {
    int ret = 1;
    while (n >= b) {
        ++ret;
        n /= b;
    }
    return ret;
}

bool isPal(int n, int base=10) {
    int h = digits(n, base);
    int digs[h/2];
    for(int i = 0; i < h; ++i) {
        if (i < h/2) digs[i] = n%base;
        else if((h&1) && i == h/2) ;
        else {
            if (digs[h-i-1] != n%base) return false;
        }
        n /= base;
    }
    return true;
}

int main() {
    int mx = 0;
    for(int i = 100; i < 1000; ++i) {
        for(int j = i; j < 1000; ++j) {
            if (isPal(i*j) && i*j > mx) mx = i*j;
        }
    }
    cout << mx << endl;
    cin.get();
    return 0;
}
