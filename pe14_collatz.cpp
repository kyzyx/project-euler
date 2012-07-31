// pe14

#include <iostream>

using namespace std;

int steps[10000000];

int ns(unsigned long long n) {
  if (n < 10000000 && steps[n] != 0) return steps[n];
  else {
    int ret;
    if (n % 2 == 0) {
      ret = ns(n/2)+1;
      if (n < 10000000) steps[n] = ret;
    }
    else {
      ret = ns(3*n+1)+1;
      if (n < 10000000) steps[n] = ret;
    }
    return ret;
  }
}

int main() {
  for(int i = 0; i < 10000000; i++) steps[i] = 0;
  steps[1] = 1;
  int ms = 1;
  int mi = 0;
  for(int i = 2; i < 1000000; i++) {
    int cs = ns(i);
    if (cs > ms) {
      ms = cs;
      mi = i;
    }
  }
  cout << mi << endl;
  return 0;
}