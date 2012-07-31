#include <iostream>
#include <vector>
#include <gmp.h>
#include <gmpxx.h>
#define MAX 150000000

using namespace std;
typedef mpz_class BigInt;

int sieve = 9699690;//2*3*5*7*11*13*17*19;
int diffs[] = {2, 6, 8, 12, 26};
int works[9699718];

bool isprime[MAX];
vector<int> primes;

void init() {
	for(int i = 0; i < MAX; i++) isprime[i] = true;
	for(int i = 2; i < MAX; i++) {
		if (isprime[i]) {
			primes.push_back(i);
			for(int j = i*2; j < MAX; j += i) isprime[j] = false;
		}
	}
}

int main() {
	cout << sieve << endl;

    for(int i = 1; i < sieve + 28; ++i) {
        if (i%2 == 0 || i%3 == 0 || i%5 == 0 || i%7 == 0 || i%11 == 0 || i%13 == 0 || i%17 == 0 || i%19 == 0)
            works[i] = 0;
        else
            works[i] = 1;
    }
    vector<int> valid;
    int tst = 0;
    for(int i = 1; i < sieve; i += 2) {
        if (!works[i]) continue;
        ++tst;
        bool cand = true;
        for(int j = 0; j < 5; j++) {
            int k = (i + diffs[j]) % sieve;
            if (!works[k]) {
                 cand = false;
                 break;
            }
        }
        if (cand) {
            valid.push_back(i);
            //cout << i << endl;
            works[i] = 2;
        }
    }
    cout << valid.size() << "/" << sieve << endl;

    int total = 0;
    BigInt tmp, t;
    for(int i = 10; i < MAX; i+=10) {
        long long sq = i;
        sq = sq*sq + 1;
        if (works[sq % sieve] != 2) continue;
        t = BigInt(i);
        t = t*t + 1;
        if (!mpz_probab_prime_p(t.get_mpz_t(), 8)) continue;
        bool cand = true;
        tmp = t;
        for(int j = 0; j < 5; j++) {
			mpz_nextprime(tmp.get_mpz_t(), tmp.get_mpz_t());
			if (tmp - t != diffs[j]) {
				cand = false;
				break;
			}
		}
		if (cand) total += i;
    }

    cout << total << endl;
    return 0;
}
