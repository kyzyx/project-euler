#include <iostream>
#include <fstream>
#define R 15

using namespace std;

int tri[R][R];
int best[R][R];


int main() {
    ifstream in("Inputs/triangle_.txt");
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j <= i; ++j) {
            in >> tri[i][j];
            best[i][j] = 0;
        }
    }
    best[0][0] = tri[0][0];
    for(int i = 1; i < R; ++i) {
        for(int j = 0; j <= i; ++j) {
            best[i][j] = best[i-1][j] + tri[i][j];
            if (j != 0 && best[i-1][j-1] + tri[i][j] > best[i][j]) best[i][j] = best[i-1][j-1] + tri[i][j];
        }
    }
    
    int mx = 0;
    for(int i = 0;i < R-1; ++i) {
        if (best[R-1][i] > mx) mx = best[R-1][i];
    }
    
    cout << mx << endl;
    cin.get();
    return 0;
}
