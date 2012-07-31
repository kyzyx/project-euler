// http://www.mathpages.com/home/kmath243.htm
// http://www.alpertron.com.ar/QUAD.HTM
#include <iostream>
#include <set>

using namespace std;

set<long long> sols;

int main() {
  int P = 3, Q=4, K=1, R=2, S=3, L=1;

  long long x[] = {0, -1, -1, -3};
  long long y[] = {-1, -1, 1, 2};
  while(sols.size() < 100) {
    for(int i = 0; i < 4; i++) {
       long long tx = x[i];
       long long ty = y[i];
       x[i] = P*tx + Q*ty + K;
       y[i] = R*tx + S*ty + L;
       if (x[i] > 0 && y[i] > 1) {
        sols.insert(y[i]-1);
        if (sols.size() == 100) break;
       }
    }
  }
  unsigned long long tot = 0;
  int i = 1;
  for(set<long long>::iterator it = sols.begin(); it != sols.end(); ++it) {
    tot += *it;
    cout << i++ << ": " << *it << "=" << tot << endl;
    if (i == 41) break;
  }
  cout << tot << endl;
cin.get();
  return 0;
}
