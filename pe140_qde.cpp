// http://www.mathpages.com/home/kmath243.htm
// http://www.alpertron.com.ar/QUAD.HTM
#include <iostream>
#include <set>

using namespace std;

set<long long> sols;

int main() {
  int P = -9, Q=-4, K=-14, R=-20, S=-9, L=-28;

  long long x[] = {0, 0, -3, -3, -4, -4, 2, 2};
  long long y[] = {-1, 1, -2, 2, -5, 5, -7, 7};
  sols.insert(2);
  while(sols.size() < 100) {
    for(int i = 0; i < 8; i++) {
       long long tx = x[i];
       long long ty = y[i];
       x[i] = P*tx + Q*ty + K;
       y[i] = R*tx + S*ty + L;
       if (x[i] > 0 && y[i] > 0) {
        sols.insert(x[i]);
        if (sols.size() == 100) break;
       }
    }
  }
  unsigned long long tot = 0;
  int i = 1;
  for(set<long long>::iterator it = sols.begin(); it != sols.end(); ++it) {
    tot += *it;
    cout << i++ << ": " << *it << "=" << tot << endl;
    if (i == 31) break;
  }
  cout << tot << endl;

  return 0;
}
