#include <iostream>
#include <cstring>
#define MAX 100000000
#define SQRTMAX 10000

using namespace std;

int gcd(int a, int b) {
  if (a < b) return gcd(b, a);
  int tmp;
  while (b > 0) {
    tmp = a;
    a = b;
    b = tmp%b;
  }
  return a;
}

unsigned long long ss(int p) {
  unsigned long long ret = 0;
  unsigned long long a = MAX/p;

  unsigned long long t = 1;
  unsigned long long tmp;
  unsigned long long ind = a;
  while(t <= a) {
    tmp = a/(t+1);
    ret += t*(ind + tmp + 1)*(ind-tmp)/2;
    ind = tmp;
    if (tmp == 0) break;
    t = a/tmp;
  }
  return ret;
}

int main() {
  unsigned long long ttot = 0;
  for(int i = 1; i <= MAX; ++i) {
    ttot += i*(MAX/i);
  }

  cout << "Done a" << endl;
  unsigned long long tot = 0;
  for(int i = 1; i < SQRTMAX; ++i) {
    for(int j = i; j < SQRTMAX; ++j) {
      int prod = i*i + j*j;
      if (prod > MAX) break;
      if (gcd(i, j) != 1) continue;
      if (i == j) tot += 2*i*ss(prod);
      else tot += 2*(i+j)*ss(prod);
    }
    if (i%100 == 0) cout << i << endl;
  }
  cout << ttot + tot << endl;
  return 0;
}