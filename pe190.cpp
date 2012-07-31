#include <iostream>
#include <cstdio>
#define dx 1e-9
#define EPS 1e-15
#define abs(a) ((a)>0?(a):-(a))

using namespace std;

double fraction[16];

double pow(double a, int b) {
  double ret = 1;
  for(int i = 0; i < b; i++) ret *= a;
  return ret;
}

double prod(int n, double f) {
  double ret = pow(n*f, n);
  double remaining = n - n*f;

  for(int i = n-1; i > 0; --i) {
    double a = remaining*fraction[i];
    ret *= pow(a, i);
    remaining -= a;
  }
  return ret;
}

bool equals(double a, double b) {
  return abs(a-b) <= EPS;
}

int isIncreasing(double guess, int n) {
  double a = prod(n, guess - dx);
  double b = prod(n, guess);
  double c = prod(n, guess + dx);

  //printf("%.10f: %.12f %.12f %.12f\n", guess, a, b, c);
  if (equals(a, b) || equals(b, c) || (a < b && c < b)) {
    return 0;
  }
  else if (a<b && b<c) return 1;
  else if(a>b && b>c) return -1;
  else {
    return 0;
  }
}

double search(double hi, double lo, int n) {
  double guess = (hi + lo) / 2;
  int dy = isIncreasing(guess, n);
  if (dy == 0) {
    return guess;
  }
  else if (dy == 1) {
    return search(hi, guess, n);
  }
  else if(dy == -1) {
    return search(guess, lo, n);
  }
  else {
    return 0;
  }
}

int main() {
  fraction[0] = 1;
  fraction[1] = 1;
  fraction[2] = 2./3;

  // Smart way:
  // for(int i = 2; i <= 15; i++) fractions[i] = 2./(i+1);

  int total = 0;
  for(int i  = 2; i <= 15; i++) {
    fraction[i] = search(1, 0, i);
    double tmp = prod(i, fraction[i]);
    cout << i << ": " << fraction[i] << " " << tmp << endl;
    total += (int) tmp;
  }

  cout << total << endl;
}

