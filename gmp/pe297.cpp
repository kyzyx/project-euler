#include <iostream>
#include <vector>
#include <cstring>
#include <gmp.h>
#include <gmpxx.h>

using namespace std;
typedef mpz_class BigInt;


vector<BigInt> f;
int nf, mf;
BigInt numways[100][100][2];
BigInt lim;

// Current sum, highest unused element, number used
BigInt numOver(BigInt cs, int m, int nu) {
  if (m < 2) return 0;
  BigInt ret = 0;

  for(int i = m; f[i+2] + cs >= lim; --i) {
    if (cs + f[i] >= lim) {
      for(int j = 1; j < mf+1; ++j) {
        ret += (nu+j)*(numways[j][i+1][0]);
      }
    }
    else {
      ret += numOver(cs + f[i], i-2, nu+1);
    }
  }
  return ret;
}

int main() {
  lim = BigInt("100000000000000000");

  // Determine largest fibonaci number
  f.push_back(1);
  f.push_back(2);
  for(int i = 0; f[i] < lim; ++i) {
    f.push_back(f[i] + f[i+1]);
  }
  nf = f.size()-2;
  mf = (nf+1)/2;
  cout << nf << " fibonacci numbers" << endl;
  // Generate counting table
  for(int i = 0; i < mf+1; ++i) {
    for(int j = 0; j < nf+1; ++j) {
      numways[i][j][0] = 0; numways[i][j][1] = 0;
    }
  }
  numways[0][0][1] = 1;
  for(int i = 0; i < mf+1; ++i) {
    for(int j = i; j < nf+1; ++j) {
      if (i > 0) numways[i][j][0] = numways[i-1][j-1][1];
      if (j > 0) numways[i][j][1] = numways[i][j-1][0] + numways[i][j-1][1];
    }
  }
  /*
  for(int i = 0; i < mf+1; ++i) {
    for(int j = 0; j < nf+1; ++j) {
      cout << numways[i][j][0] << "/" << numways[i][j][1] << " ";
     }
     cout << endl;
  }*/
  BigInt tot = 0;
  for(int i = 0; i < mf+1; ++i) {
    tot += i*(numways[i][nf][0] + numways[i][nf][1]);
  }
  // Calculate how many of these sets have sum >= LIMIT
  BigInt tov = numOver(0, nf-1, 0);

  cout << tot << " - " << tov << " = " << tot - tov  << endl;
  return 0;
}
