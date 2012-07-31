#include <iostream>
#include <vector>
#define MAX 1000000

using namespace std;

bool isprime[MAX];
vector<int> primes;

long long powmod(long long a, long long b, int m) {
  long long res = 1;
  long long pow = a;

  while(b > 0) {
    if (b&1) {
      res = res*pow % m;
    }
    pow = pow*pow % m;
    b >>= 1;
  }

  return res;
}

bool ipf(int p) {
  if (powmod(10, 1000000000, p) == 1) return true;
  return false;
}

int main() {
  long long tot = 0;
  int n = 0;
  for(int i = 0; i < MAX; i++) isprime[i] = true;
  for(int i = 2; i < MAX; i++) {
    if (isprime[i]) {
      primes.push_back(i);
      if (i > 5 && ipf(i)) {
        cout << i << endl;
        ++n;
        tot += i;
        if (n == 40) break;
      }
      for(int j = 2*i; j < MAX; j += i) isprime[j] = false;
    }
  }

  cout << tot << endl;
  
  cin.get();
  return 0;
}
