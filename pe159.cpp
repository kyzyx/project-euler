#include <iostream>
#include <vector>
#define MAX 1000000

using namespace std;

int mdrs[MAX];

int isprime[MAX];
vector<long> primes;

int drs(int n) {
  int ret = 0;
  while(n > 0) {
    ret += n%10;
    n /= 10;
  }
  if (ret >= 10) return drs(ret);
  else return ret;
}

void getmdrs(int n) {
  mdrs[n] = drs(n);
  if (isprime[n] == -1) return;
  for(int i = isprime[n]; i < n; i += isprime[n]) {
    if (n%i == 0) {
      if (mdrs[i] + mdrs[n/i] > mdrs[n]) mdrs[n] = mdrs[i] + mdrs[n/i];
    }
  }
}

int main() {
  for(int i = 0; i < MAX; ++i) {
    isprime[i] = -1;
    mdrs[i] = 0;
  }
  for(int i = 2; i < MAX; ++i) {
    if (isprime[i] == -1) {
      primes.push_back(i);
      mdrs[i] = drs(i);
      for(int j = 2*i; j < MAX; j += i) {
        isprime[j] = i;
      }
    }
  }

  for(int i = 0; i < primes.size(); ++i) {
    for(int j = i; j < primes.size() && primes[i]*primes[j] < MAX; ++j) {
      mdrs[primes[i]*primes[j]] = mdrs[primes[i]] + mdrs[primes[j]];
      if (drs(primes[i]*primes[j]) > mdrs[primes[i]*primes[j]])
        mdrs[primes[i]*primes[j]] = drs(primes[i]*primes[j]);
    }
  }

  long tot = 0;
  for(int i = 2; i < MAX; ++i) {
    if(mdrs[i] == 0) {
      getmdrs(i);
    }
    tot += mdrs[i];
    if (i%5000 == 0) cout << i << endl;
  }
  cout << tot << endl;
  return 0;
}
