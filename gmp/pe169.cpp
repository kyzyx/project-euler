// pe169
#include <iostream>
#include <cstring>
#include <string>
#include <gmp.h>
#include <gmpxx.h>
#define M 30

using namespace std;
typedef mpz_class BigInt;

// Takes reversed binary representation
BigInt numways(string bin) {
  BigInt A[M];
  BigInt B[M];            // B[i] = TB[pos[i]]
  BigInt BB[bin.size()];
  BigInt TB[bin.size()];  // TB[i] = Sum of BB[0..i]

  A[0] = 1;
  B[0] = 0;
  int z = 1;
  for(int i = 0; i < bin.size(); ++i) {
    if (bin[i] == '1') {
      A[z] = A[z-1] + B[z-1];
      TB[i] = i==0?0:TB[i-1];
      B[z] = TB[i];
      BB[i] = 0;
      ++z;
    }
    else {
      BB[i] = A[z-1] + B[z-1];
      TB[i] = (i==0?0:TB[i-1]) + BB[i];
    }
  }
  return A[z-1] + B[z-1];
}

int main() {
  BigInt t = 1;
  for(int i = 0; i < 25; i++) t *= 10;

  // Get reversed binary representation
  string binrep = "";
  while(t > 0) {
    if (t%2 == 0) binrep += '0';
    else          binrep += '1';
    t /= 2;
  }

  BigInt tt = numways(binrep);
  cout << tt << endl;

  return 0;
}