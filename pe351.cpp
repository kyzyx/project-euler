#include <iostream>
#define M 100000001

using namespace std;

// Calculate euler totient
long long totient[M];

bool prime[M];

int main() {
    for (int i = 0; i < M; ++i) {
        totient[i] = i;
        prime[i] = true;
    }

    for (int i = 2; i < M; ++i) {
        if (prime[i]) {
            totient[i] -= 1;
            for (int j = i*2; j < M; j += i) {
                prime[j] = false;
                totient[j] /= i;
                totient[j] *= (i-1);
            }
        }
    }

    long long tot = 0;
    for (int i = 1; i < M; ++i) {
        tot += i - totient[i];
    }

    cout << 6*tot << endl;
    return 0;
}
