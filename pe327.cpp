#include <iostream>
#define R 31
#define C 40

using namespace std;

unsigned long long cards(int r, int c) {
    if (r <= c) return r;
    unsigned long long numneeded[r];
    for(int i = 0; i < r; i++) {
        if (i+1 <= c) {
            numneeded[i] = i+1;
            //cout << numneeded[i] << " ";
            continue;
        }
        unsigned long long stored = numneeded[i-1]-1;
        unsigned long long storable = c-2;
        unsigned long long trips = (stored + storable - 1)/storable;
        numneeded[i] = trips*2 + numneeded[i-1] - 1;
        //cout << numneeded[i] << " ";
    }
    return numneeded[r-1];
}

int main() {
    unsigned long long tot = 0;
    for(int i = 3; i <= C; i++) {
        tot += cards(R, i);
    }
    cout << tot << endl;
    cin.get();
    return 0;
}
