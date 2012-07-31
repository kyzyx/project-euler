#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#define D 15
#define N 200
#define MAX_STEPS 100000

using namespace std;

int t[N];
int b[N];
int v[N];
int perm[N][D];
int m[D][D];

int ev(int n) {
    int tot = 0;
    for (int i = 0; i < D; ++i) {
        tot += m[i][perm[n][i]];
    }
    return tot;
}

void shuffle(int n) {
    for (int i = D-1; i > 0; --i) {
        int j = rand()%i;
        int tmp = perm[n][i];
        perm[n][i] = perm[n][j];
        perm[n][j] = tmp;
    }
}

int main() {
    srand(time(0));

    for (int i = 0; i < D; ++i) {
        for (int j = 0; j < D; ++j) {
            cin >> m[i][j];
        }
    }
    cerr << "Done input" << endl;
    // Generate random initial permutation
    for (int j = 0; j < N; ++j) {
        v[j] = 0;
        b[j] = 0;
        t[j] = 0;
        for (int k = 0; k < D; ++k) perm[j][k] = k;
        shuffle(j);
    }
    cerr << "Done generation" << endl;
    // Greedy hill climbing
    for (int i = 0; i < MAX_STEPS; ++i) {
        for (int j = 0; j < N; ++j) {
            int r = rand()%D;
            int r2 = rand()%D;
            while (r == r2) r2 = rand()%D;
            // Swap
            int tmp = perm[j][r];
            perm[j][r] = perm[j][r2];
            perm[j][r2] = tmp;
            // Evaluate
            int val = ev(j);
            if (val > v[j]) {
                v[j] = val;
                if (v[j] > b[j]) b[j] = v[j];
                t[j] = i;
            }
            else {
                // swap back
                int tmp = perm[j][r];
                perm[j][r] = perm[j][r2];
                perm[j][r2] = tmp;
            }
        }
    }

    int best = 0;
    for (int j = 0; j < N; ++j) {
        cout << t[j] << ": " << b[j] << endl;
        if (b[j] > best) best = v[j];
    }
    cout << best << endl;
    return 0;
}
