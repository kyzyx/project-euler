#include <iostream>
#define MAX 1001

using namespace std;

int ns[MAX];

int main() {
    for(int i = 0; i < MAX; ++i) ns[i] = 0;
    for(int i = 1; i < MAX; ++i) {
        for(int j = i; j < MAX-i; ++j) {
            for(int k = j; k < MAX-i-j;++k) {
                if (i*i + j*j == k*k) ++ns[i+j+k];
            }
        }
    }
    int mi = 0;
    int mx = 0;
    for(int i = 0; i < MAX; ++i) {
        if (ns[i] > mx) {
            mi = i;
            mx = ns[i];
        }
    }
    cout << mi << endl;
    cin.get();
    return 0;
}
