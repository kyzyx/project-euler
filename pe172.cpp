#include <iostream>

using namespace std;

int countn(int n) {
    int ret = 0;
    while (n > 0) {
        ret += n&3;
        n >>= 2;
    }
    return ret;
}

int main() {
    int lim = 1;
    for(int i = 0; i < 10; i++) lim *= 4;
    unsigned long long tot = 0;
    
    unsigned long long facs[19];
    facs[0] = 1;
    for(int i = 1; i < 19; i++) {
        facs[i] = facs[i-1]*i;
    }
    
    for(int i = 0; i < lim; i++) {
        if (countn(i) == 17) {
            unsigned long long add = facs[17];
            int tmp = i;
            int possible = 0;
           // cout << tmp << ": ";
            for(int j = 0; j < 10; j++) {
                add /= facs[tmp&3];
                if ((tmp&3) != 3 && j != 0) ++possible;
             //   cout << (tmp&3) << " ";
                tmp >>= 2;
            }
            //cout << "=" << possible << endl;
            tot += add*possible;
            //cin.get();
        }
    }
    cout << tot << endl;
    
    cin.get();
    return 0;
}
