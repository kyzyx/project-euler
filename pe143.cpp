#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#define MAX 120000
#define fori(m,n) for(long long i = m; i < n; ++i)

/*2:20 for 10^7*/

using namespace std;

int sqf[MAX];
bool isprime[MAX];
bool possible[MAX+1];
vector<int> primes;
vector<int> triangles[MAX];

typedef vector<int>::iterator vii;

int main() {
  fori(0,MAX) {
    isprime[i] = true;
    sqf[i] = 1;
    possible[i] = false;
  }
  possible[MAX] = false;
  primes.push_back(1);  // NOT REALLY A PRIME!
  fori(2, MAX) {
    if (isprime[i]) {
      primes.push_back(i);
      for(long long j = i*i; j < MAX; j += i*i) sqf[j] = i;
      for(int j = 2*i; j < MAX; j += i) isprime[j] = false;
    }
  }
  cout << "Done prep" << endl;
  fori(1,MAX) {
    long long n = i;
    if (n%3 == 0) n /= 3;
    long long sq = 1;
    while(sqf[n] != 1) {
      sq *= sqf[n];
      n /= sqf[n]*sqf[n];
    }
    long long p1 = sq*sq*n*n;
    for(int j = 1; sq*n*j < MAX; ++j) {
      long long nn = 3*p1*j*j;
      long long p  = sq*n*j;
      /*int x = (i*i + n)/(2*i); int y = (i*i - n)/(2*i);
      int a = x/2; int q = (y-p)/2
      cout << x << " " << y << " " << n << endl;*/

      long long a = i + nn/i;
      if (a&3LL) continue;
      a >>= 2;
      long long q;
      if (i*i > nn) q = ((i - nn/i)/2 - p)/2;
      else q = ((nn/i-i)/2 - p)/2;
      if (q <= 0 || p*p + p*q + q*q != a*a || q > MAX) continue;
      if (p > q) triangles[q].push_back(p);
      else triangles[p].push_back(q);
    }
  }

  ofstream out;
  cout << "Done constructing triangles" << endl;
  bool dbg = false;
  if (dbg) out.open("pe143.txt");
  fori(1, MAX) {
    sort(triangles[i].begin(), triangles[i].end());
    vii it = unique(triangles[i].begin(), triangles[i].end());
    triangles[i].resize(it - triangles[i].begin());
    if (dbg && triangles[i].size() > 0) {
        out << i << ": ";
        for(int j = 0; j < triangles[i].size(); ++j) out << triangles[i][j] << " ";
        out << endl;
    }
  }
  cout << "Done cleaning list" << endl;
  for(int i = 1; i < MAX; ++i) {
    for(vii j = triangles[i].begin(); j != triangles[i].end(); ++j) {
      for(vii k = j; k != triangles[i].end(); ++k) {
        if (i + *j + *k > MAX) break;
        if (binary_search(triangles[*j].begin(), triangles[*j].end(), *k)) {
            possible[i+*j+*k] = true;
        }
      }
    }
  }
  cout << "Done process" << endl;
  long long tot = 0;
  for(int i = 0; i <= MAX; ++i) {
    if (possible[i]) tot += i;
  }
  cout << tot << endl;
  cin.get();
  return 0;
}
