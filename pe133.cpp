#include <iostream>
#include <set>
#define MAX 100000

using namespace std;

bool isprime[MAX];

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

bool works(int p) {
  if (p == 3) return true;
  set<long long> rems;
  long long t = powmod(10, 10, p);
  if (t == 1) return false;
  while (rems.find(t) == rems.end()) {
    rems.insert(t);
    t = powmod(t, 10, p);
    if (t == 1) return false;
  }
  return true;
}



unsigned long long order(unsigned long long n, unsigned long long p) {
  unsigned long long ret = 1;
  unsigned long long phi = 2*3*(p-1);
  unsigned long long currp = 1;

  for(ret = 1; ret <= phi; ++ret) {
    currp = (currp*n) % (9*p);
    if (phi % ret == 0 && currp == 1) break;
  }

  while (ret % 2 == 0) ret /=2;
  while (ret % 5 == 0) ret /=5;
  return ret;
}


int main() {
  /*unsigned long long tot = 0;
  for(int i = 0; i < MAX; i++) isprime[i] = true;
  for(int i = 2; i < MAX; i++) {
    if (isprime[i]) {
      if (works(i)) {
        tot += i;
      }
      else {
        cout << i << endl;
      }
      for(int j = 2*i; j < MAX; j += i) isprime[j] = false;
    }
  }

  cout << tot << endl;
  return 0;*/
  //Smarter
  unsigned long long tot = 2+3+5;
    for(int i = 0; i < MAX; i++) isprime[i] = true;
    for(int i = 2; i < MAX; i++) {
      if (isprime[i]) {
        if (i > 5) {
          if (order(10, i) != 1) {
            tot += i;
          }
        }
        for(int j = 2*i; j < MAX; j += i) isprime[j] = false;
      }
    }
  
    cout << tot << endl;
  cin.get();
  return 0;
  
}
