/*
 * Found the formula.
 * Brute force counting, dimensions up to 7000, maximum guess 100000 
 * Finds answer in 7:18
 * */
#include <iostream>
#define D 30

using namespace std;

long long tri(long long n) {
    return (n*(n+1))/2;
}

long long formula(long long a, long long b, long long c, int l) {
    if (l == 0) return a*b*c;
    if (l == 1) return 2*(a*b + a*c + b*c);
    if (l == 2) return formula(a,b,c,1) + 4*(a+b+c);
    return formula(a,b,c,1) + (l-1)*4*(a+b+c) + tri(l-2)*8;
}

int x[] = {1,-1,0,0,0,0};
int y[] = {0,0,1,-1,0,0};
int z[] = {0,0,0,0,1,-1};

void printLayers(int a, int b, int c, int m) {
    int layer[D][D][D];
    for (int i = 0; i < D; ++i) {
        for (int j = 0; j < D; ++j) {
            for (int k = 0; k < D; ++k) {
                layer[i][j][k] = 0;
            }
        }
    }
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            for (int k = 0; k < c; ++k) {
                layer[i+m][j+m][k+m] = 1;
            }
        }
    }
    cout << a*b*c << " ";
    for (int l = 1; l <= m; ++l) {
        int d = 0;
        for (int i = 0; i < D; ++i) {
            for (int j = 0; j < D; ++j) {
                for (int k = 0; k < D; ++k) {
                    if (layer[i][j][k] == l) {
                        for (int n = 0; n < 6; ++n) {
                            if (!layer[i+x[n]][j+y[n]][k+z[n]]) {
                                layer[i+x[n]][j+y[n]][k+z[n]] = l+1;
                                ++d;
                            }
                        }
                    }
                }
            }
        }
        cout << d << " ";
        if (d != formula(a,b,c,l)) cout << "(" << formula(a,b,c,l) << ")";
    }
}

#define M 7000
#define lim 100000
void count() {
    int nways[lim];
    for (int i = 0; i < lim; ++i) nways[i] = 0;
    for (int i = 1; i <= M; ++i) {
        for (int j = i; j <= M; ++j) {
            for (int k = j; k <= M; ++k) {
                for (int l = 1; l < M; ++l) {
                    long long a = formula(i,j,k,l);
                    if (a < lim) {
                        ++nways[a];
                    }
                    else break;
                }
            }
        }
        if (i%100 == 0) cout << i << endl;
    }
    for (int i = 0; i < lim; ++i) {
        if (nways[i] == 1000) {
            cout << i << endl;
            break;
        }
    }
}

int main() {
    /*int max_layers = 9;
    int max_dim = 6;

    for (int i = 1; i <= max_dim; ++i) {
        for (int j = i; j <= max_dim; ++j) {
            for (int k = j; k <= max_dim; ++k) {
                cout << i << "x" << j << "x" << k << ": ";
                printLayers(i,j,k,max_layers);
                cout << endl;
            }
        }
    }*/
    count();
}
