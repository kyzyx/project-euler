#include <iostream>
#include <cmath>
#define MAXI 500005
#define MAX 1000000
using namespace std;

int nsols[MAX];
typedef unsigned long long ull;

int main() {
    for(int i = 0; i < MAX; i++) {
        nsols[i] = 0;
    }
    
    for(ull i = 0; i<MAXI; i++) {
        ull jjn = ceil(sqrt((i*i + MAX)/4));
        //cout << jj << " " << jjn << endl;
        //cin.get();
        for(ull j = i/2 + 1; j < jjn + 1; j++) {
            ull n = 4*j*j - i*i;
            if (n > MAX) break;
            nsols[n]++;

            ull a = 2*j - i;
            if (a > j && i != 0) {
                nsols[n]++;
            }
        }
        //cout << i << endl;
        //cin.get();
    }
    
    int n = 0;

    for(int i = 0; i < MAX; i++) {
        if ( nsols[i] == 10) n++;
    }
    cout << n << endl;
    cin.get();
    return 0;
}
