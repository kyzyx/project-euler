#include <iostream>
#include <stack>
#include <queue>

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

int makePal(int n, int d = -1) {
    int ret = 0;
    vector<int> digs;
    while(n > 0) {
        digs.push_back(n%10); n/=10;
    }
    for(int i = digs.size()-1; i >=0; --i) {
        ret += digs[i]; ret *= 10;
    }
    if (d != -1) {
        ret += d;
        ret *= 10;
    }
    for(int i = 0; i < digs.size(); ++i) {
        ret += digs[i]; ret *= 10;
    }    
    return ret/10;
}

int main() {
    int tot = 0;
    for(int i = 0; i < 1000; ++i) {
        for(int j = -1; j < 10; ++j) {
            int p = makePal(i, j);
            if (p > 1000000) break;
            if (isPal(p, 2)) tot += p;
        }
    }
    cout << tot << endl;
    cin.get();
    return 0;
}
