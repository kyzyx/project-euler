// pe10
#include <iostream>
#define MAX 2000000

using namespace std;

bool isprime[MAX];

int main() {
  long long sum = 0;
  for(int i = 0; i < MAX; i++) isprime[i] = true;
  for(int i = 2; i < MAX; i++) {
    if (isprime[i]) {
      sum += i;
      for(int j = 2*i; j < MAX; j+=i) isprime[j] = false;
    }
  }
  cout << sum << endl;
  return 0;
}
