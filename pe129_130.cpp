#include <iostream>
#include <vector>
#define MAX 5000000

using namespace std;

bool isprime[MAX];
vector<long long> primes;

long long cphi(long long n) {
  unsigned long long ret = n;
  for(int i = 0; primes[i] <= n && i < primes.size(); ++i) {
    if (n % primes[i] == 0) {
      ret /= primes[i];
      ret *= (primes[i]-1);
    }
  }
  return ret;
}

unsigned long long order10(unsigned long long p) {
  unsigned long long ret = 1;
  unsigned long long phi = cphi(p);
  unsigned long long currp = 1;

  for(ret = 1; ret < p; ++ret) {
    currp = (currp*10) % (p);
    if (currp == 1) break;
  }

  return ret;
}

int main() {
  for(int i = 0; i < MAX; i++) isprime[i] = true;
  for(int i = 2; i < MAX; i++) {
    if (isprime[i]) {
      primes.push_back(i);
      for(int j = 2*i; j < MAX; j += i) isprime[j] = false;
    }
  }
  // PE129
  for(int i = 1000001; i < MAX; i += 2) {
    if (i%5 == 0) continue;
    unsigned long long o = order10(9*i);
    if (o > 1000000) {
      cout << i << endl;
      break;
    }
  }
  // PE130
  int cnt = 0;
  int tot = 0;
  for(int i = 81; i < MAX; i += 2) {
    if (i%5 == 0) continue;
    if (isprime[i]) continue;
    unsigned long long o = order10(9*i);
    if ((i-1) % o == 0) {
      cout << i << endl;
      tot += i;
      ++cnt;
      if (cnt == 25) break;
    }
  }
  cout << tot << endl;

  cin.get();
  return 0;
}

