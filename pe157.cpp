#include <iostream>
#include <cmath>
#include <vector>
#define N 9

using namespace std;

long long countfactors(long long n) {
    int lim = sqrt(n);
    int tot = 0;
    for (int i = 1; i <= lim; ++i) {
        if (n%i == 0) ++tot;
    }
    if (lim*lim == n) return 2*tot - 1;
    else return 2*tot;
}

long long pow5[N+1];
int facs[200];

int main() {
    long long tot = 0;
    pow5[0] = 1;
    for (int i = 1; i < N+1; ++i) {
        pow5[i] = 5*pow5[i-1];
    }
    for (int i = 1; i <= N; ++i) {
        // Generate all pairs naively: first generate all factors of 10^i
        int nfacs = 0;
        for (int j = 0; j <= i; ++j) {
            for (int k = 0; k <= i; ++k) {
                facs[nfacs++] = (1<<j)*pow5[k];
            }
        }
        for (int j = 0; j < nfacs; ++j) {
            for (int k = j; k < nfacs; ++k) {
                // toss out pairs with a common factor
                if ((!(facs[j] & 1) && !(facs[k] & 1)) || (facs[j]%5 == 0 && facs[k]%5 == 0)) continue;
                // Count factors
                long long target = pow5[i]*(1<<i)*(facs[j] + facs[k])/(facs[j]*facs[k]);
                tot += countfactors(target);
            }
        }
        cout << i << ": " << tot << endl;
    }

    return 0;
}
