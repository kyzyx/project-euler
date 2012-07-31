#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#include <vector>
#define M 1000000
#define MAX 1000000

using namespace std;

typedef mpz_class BigInt;

bool areprime(BigInt a, BigInt b, BigInt c) {
    return mpz_probab_prime_p(a.get_mpz_t(), 7) &&
           mpz_probab_prime_p(b.get_mpz_t(), 7) &&
           mpz_probab_prime_p(c.get_mpz_t(), 7);
}

int main() {
    int goal = 2000;
    // Since all "non-corner" tiles have two adjacent with diff 1, and of the
    // other 4 they differ by 1 each, so can have max 2. Therefore, just check
    // "corners", which can only have 3 prime differences from the corner one
    // inwards, and twin primes on the outward OR if it is the northward one,
    // the prime differences are lower right, upper right, upper left.

    BigInt m = 8, m1 = 20, m2 = 38, mp = 2;
    int count = 2;

    //cout << "Ready" << endl;
    for(int i = 2; i < M; i++) {
        BigInt da = m2 - 1 - m;
        BigInt db = m1 + 1 - m;
        BigInt dc = m1 - 1 - m;
        if (areprime(da, db, dc)) {
            cout << ++count << "(a" << i << "): " << m << endl;
            if (count == goal) {
                break;
            }
        }
        BigInt t = m1 - 1;
        da = t - m;
        db = t - mp;
        dc = m2 - 1 - t;
        if (dc % 2 == 0) --dc;
        if (areprime(da, db, dc)) {
            cout << ++count << "(t" << i << "): " << t << endl;
            if (count == goal) {
                break;
            }
        }
        mp = m;
        m = m1;
        m1 = m2;
        m2 = 2*m2 - m + 6;
    }

    cin.get();
    return 0;
}
