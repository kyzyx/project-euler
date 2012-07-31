#include <iostream>
#include <set>

using namespace std;

long long M = 1000000000000LL;
long long sqrtM = 1000000LL;

int main() {
    set<long long> reps;
    for (long long i = 2; i < sqrtM; ++i) {
        long long c = i*i;
        long long t = 1+i+c;
        while (t < M) {
            reps.insert(t);
            c *= i;
            t += c;
        }
    }

    long long tot = 1;
    for (set<long long>::iterator it = reps.begin(); it != reps.end(); ++it) {
        tot += *it;
    }

    cout << "Total: " << tot << endl;
    return 0;
}
