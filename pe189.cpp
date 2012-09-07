#include <iostream>
#define R 8
#define P38 6561

using namespace std;

unsigned long long pow3[R+1];
unsigned long long n1[R+1][P38];
unsigned long long n2[R][P38];

bool comp1(int a, int b, int l) {
    for (int i = 0; i < l; ++i) {
        if (a%3 == b%3) return false;
        a /= 3; b /= 3;
    }
    return true;
}
bool comp2(int a, int b, int l) {
    // l gives length of a
    int b3 = b%3;
    b /= 3;
    for (int i = 0; i < l; ++i) {
        int a3 = a%3;
        a /= 3;
        if (a3 == b3) return false;
        b3 = b%3;
        b /= 3;
        if (a3 == b3) return false;
    }
    return true;
}

void printr(int a, int l) {
    for (int i = 0; i < l; ++i) {
        cout << (char)('A' + (a%3));
        a/=3;
    }
}

int main() {
    pow3[0] = 1;
    for (int i = 0; i < R; ++i) pow3[i+1] = 3*pow3[i];
    for (int i = 0; i < R+1; ++i) {
        for (int j = 0; j < P38; ++j) {
            n1[i][j] = 0;
        }
        if (i == R) break;
        for (int j = 0; j < P38; ++j) {
            n2[i][j] = 0;
        }
    }


    for (int i = 0; i < 3; ++i) n1[0][i] = 1;  // Top triangle can be 3 colors
    for (int r = 1; r <= R; ++r) {
        for (int i = 0; i < pow3[r]; ++i) {
            for (int j = 0; j < pow3[r]; ++j) {
                if (comp1(i,j,r)) n2[r-1][j] += n1[r-1][i];
            }
        }
        for (int i = 0; i < pow3[r]; ++i) {
            for (int j = 0; j < pow3[r+1]; ++j) {
                if (comp2(i,j,r)) {
                    n1[r][j] += n2[r-1][i];
                }
            }
        }
    }

    /*
    for (int i = 0; i <= R; ++i) {
        cout << i << ": ";
        for (int j = 0; j < pow3[i+1]; ++j) {
            cout << n1[i][j] << " ";
        }
        cout << endl;
        if (i == R) break;
        cout << i << ": ";
        for (int j = 0; j < pow3[i+1]; ++j) {
            cout << n2[i][j] << " ";
        }
        cout << endl;
    }
*/
    // Count total configurations
    unsigned long long tot = 0;
    for (int i = 0; i < pow3[R]; ++i) {
        tot += n1[R-1][i];
    }
    cout << tot << endl;
}
