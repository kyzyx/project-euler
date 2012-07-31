//pe304.cpp
// 18s on dev server
// Faster to calculate fibonacci numbers from 10^14. could also use periodicity
#include <iostream>
#include <cstring>
#include <gmp.h>
#include <gmpxx.h>
#include <map>

using namespace std;
typedef mpz_class BigInt;

map<BigInt, BigInt> fib;

BigInt f(BigInt n, BigInt mod) {
  if (fib.find(n) == fib.end()) {
    BigInt fn = f(n/2, mod);
    if (n%2 == 0) {
      BigInt f1 = f(n/2-1, mod);
      fib[n] = fn*(2*f1 + fn);
    }
    else {
      BigInt f1 = f(n/2 + 1, mod);
      fib[n] = fn*fn + f1*f1;
    }
    fib[n] %= mod;
  }
  return fib[n];
}

int main() {
  BigInt start = 10000000;
  start *= start;

  BigInt p = start;
  BigInt tot = 0;
  BigInt mod("1234567891011");

  fib[0] = 0;
  fib[1] = 1;
  fib[2] = 1;
  fib[3] = 2;
  fib[4] = 3;

  for(int i = 0; i < 100000; ++i) {
    mpz_nextprime(p.get_mpz_t(), p.get_mpz_t());
    tot += f(p, mod);
    tot %= mod;
    if (i% 1000 == 0) cout << i << endl;
  }

  cout << tot << endl;
  return 0;
}