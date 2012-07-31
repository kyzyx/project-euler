// 38s
#include <iostream>
#include <cstring>
#include <vector>
#include <gmp.h>
#include <gmpxx.h>
#define MAX 64000000
#define ull mpz_class

using namespace std;

int isprime[MAX];
vector<int> primes;

ull ssq[MAX];
bool iss[256];

mpz_t tmp;

bool issquare(ull n) {
  int a = mpz_tdiv_ui(n.get_mpz_t(), 256);
  if (!iss[a]) return false;
  return mpz_perfect_square_p(n.get_mpz_t());
}

void cssq(long long n) {
  int p = isprime[n];
  int pa = 1;
  int k = n;
  for(; isprime[k] == p; k /= p, pa *= p);
  ssq[n] = pa;
  ssq[n] = ssq[n/pa]*ssq[n]*ssq[n] + ssq[n/p];
}

int main() {
  for(int i = 0; i < 256; ++i) iss[i] = false;
  for(int i = 0; i < 256; ++i) {
    iss[(i*i)%256] = true;
  }
  for(int i = 0; i < MAX; ++i) isprime[i] = -1;
  for(int i = 2; i < MAX; ++i) {
    if (isprime[i] == -1) {
      primes.push_back(i);
      for(int j = i; j < MAX; j += i) {
        if (isprime[j] == -1) {
          isprime[j] = i;
        }
      }
    }
  }

  int tot = 1;
  ssq[1] = 1;
  for(int i = 2; i < MAX; ++i) {
    cssq(i);
    if (issquare(ssq[i]))
      tot += i;
    if (i%1000000 == 0) cout << i << endl;
  }

  cout << tot << endl;
  return 0;
}
