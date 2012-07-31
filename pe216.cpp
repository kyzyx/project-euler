/* 17s*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#define MAX 72000000
#define MX 50000000
#define mp make_pair

using namespace std;
typedef pair<long long, long long> pii;

long long powmod(long long n, long long a, long long p) {
  long long nn = n%p;
  long long res = 1;
  while(a>0) {
    if (a&1) {
      res = (res*nn) % p;
    }
    nn = (nn*nn) % p;
    a >>= 1;
  }
  return res;
}

pii add(pii a, pii b, long long p) {
    return mp((a.first + b.first)%p, (a.second + b.second)%p);
}

pii mult(pii x, pii y, long long n, long long a, long long p) {
    long long tmp = (((x.second*y.second) % p)*(a*a - n)) % p;
    if (tmp < 0) tmp += p;
    return mp((tmp + x.first*y.first)% p, (x.first*y.second + x.second*y.first) % p);
}

long long sqrtmod(long long n, long long p) {
  if (p%4 == 3) {
    return powmod(n, (p+1)/4, p);
  }
  // Use Cipolla
  long long a;  // sqrt(10) % 13: 2,4,5,8,9,11
  while (true) {
    a = rand() % p;
    if (powmod(((a*a - n) % p + p) % p, (p-1)/2, p) == p-1) break;
  }
  pii x = mp(a, 1);
  pii res = mp(1,0);
  long long pw = (p+1)/2;
  while(pw>0) {
    if (pw&1) {
      res = mult(res, x, n, a, p);
    }  
    x = mult(x, x, n, a, p);
    //cout << x.first << "," << x.second << endl;
    pw >>= 1;
  }
  //cout << res.first << " " << res.second << endl;
  return (res.first + p) % p;
}

bool isprime[MAX];
bool isvalid[MAX];

int main() {
  int qr = 0;
  srand(time(0));
  for(int i = 0; i < MAX; i++) {
        isprime[i] = true;
        isvalid[i] = true;
  }
  for(int i = 2; i < MAX; i++) {
    if (isprime[i]) {
      long long smod = 0;
      if (i != 2 && (i % 8 == 1 || i % 8 == 7) && powmod((i+1)/2, (i-1)/2, i) == 1) {
        smod = sqrtmod((i+1)/2, i);
        if (smod > i/2) smod = i - smod;
        //cout << i << ": " << smod << endl;
        isvalid[i-smod] = false;
        //isvalid[smod] = false;
        //cout << i-smod << " " << smod << endl;
      }
      int j;
      for(j = 2*i; j < MAX; j += i) {
        isprime[j] = false;
        if (smod) {
          isvalid[j-smod] = false;
          isvalid[j+smod-i] = false;
        }
      }
      if (smod) {
        if (j-smod < MAX) isvalid[j-smod] = false;
        if (j+smod-i < MAX) isvalid[j+smod-i] = false;
      }
    }
    if (i%1000000 == 0) cout << i << endl;
  }
  
  //cout << qr << ": " << primes.size() - qr << endl;
  int tot = 0;
  for(int i = 2; i <= MX; i++) {
    if (isvalid[i]) {
        ++tot;  
        //cout << i*i*2 - 1 << endl;
    }
  }
  cout << tot << endl;
  cin.get();
  return 0;
}
