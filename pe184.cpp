#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#define MAX 500
#define mp make_pair
#define pb push_back

#define SAME 0
#define OPPOSITE 1
#define ADJACENT 2
#define OPLINE 3

#define DBG 0

using namespace std;

typedef pair<int,int> pt;
typedef vector<pt > vp;

vp pts;
int height[MAX+1];
int ptsinquad = 0;
long long bel[MAX+1][MAX+1];
int pol[MAX+1][MAX+1];
int mm;

int abs(int a) {
  if (a>0) return a;
  return -a;
}

int cmpslope(pt a, pt b) {
  return a.first*b.second - b.first*a.second;
}

int gcd(int a, int b) {
  a = abs(a); b = abs(b);
  if (b>a) return gcd(b, a);
  while(b>0) {
    int tmp = a;
    a = b;
    b = tmp%b;
  }
  return a;
}

// Returns number of points below line through origin and a
long long below(pt a) {
  if (a.second == 0) return 0;
  else if (a.first == 0) return ptsinquad - 2*height[0];
  long long total = 0;
  for(int k = 0; k <= mm; ++k) {
    int eval = abs(k*a.second/a.first);
    if (eval > 0 && abs(eval*a.first/a.second) == k) --eval;
    if (eval > height[k]) total += height[k];
    else total += eval;
  }
  return total;
}

int ptsonline(pt a) {
  int x = abs(a.first);
  int y = abs(a.second);
  if (x == 0 || y == 0) return 0;
  if (pol[x][y] != -1) return pol[x][y];
  int g = gcd(x, y);
  int xi = abs(x/g); int yi = abs(y/g);
  int cx = xi; int cy = yi;
  int tot = 0;
  while (cx < mm && cy < mm && cx*cx + cy*cy < mm*mm) {
    ++tot;
    cx += xi; cy += yi;
  }
  pol[x][y] = tot;
  return tot;
}

int ccw(pt p, pt a, pt b) {
  return (a.first-p.first)*(b.second-p.second) -
         (a.second-p.second)*(b.first-p.first);
}

int main() {
  cin >> mm;
  for(int i = 0; i <= mm; ++i) {
    height[i] = 0;
    for(int j = 0; j <= mm; ++j) {
      pol[i][j] = -1;
    }
  }
  for(int i = 0; i <= mm; ++i) {
    for(int j = 0; j <= mm; ++j) {
      if (i == 0 && j == 0) continue;
      if (i*i + j*j >= mm*mm) break;
      ++ptsinquad;
      if (j > height[i]) height[i] = j;
      pts.pb(mp(i,j));
    }
  }

  for(int i = 0; i <= mm; ++i) {
    for(int j = 0; j <= mm; ++j) {
      if (i*i + j*j >= mm*mm) continue;
      ptsonline(mp(i,j));
      bel[i][j] = below(mp(i,j));
    }
  }

  cout << "Done prep " << pts.size() << endl;
  long long tot = 0;
  for(int i = 0; i < pts.size(); ++i) {
    long long bpi = bel[pts[i].first][pts[i].second];
    long long bpii = bel[pts[i].second][pts[i].first];
    int poli = ptsonline(pts[i]);
    if (DBG) cout << pts[i].first << "," << pts[i].second << " " << bpi << endl;
    int tto = tot;
    for(int j = i; j < pts.size(); ++j) {
      long long bpj = bel[pts[j].first][pts[j].second];
      long long bpjj = bel[pts[j].second][pts[j].first];
      int polj = ptsonline(pts[j]);
      int ttot = tot;
      long long tmp;

      if (DBG) printf("\t(%d,%d) %d ", pts[j].first, pts[j].second, bpj);
      if (pts[i].first == 0 || pts[j].first == 0) {
        if (pts[i].first == 0 && pts[j].first == 0) continue;
        if (pts[i].second == 0 || pts[j].second == 0) {
          tot += 4*(ptsinquad - 2*height[0]);
          if (DBG) cout << "Both on axes " << ptsinquad - 2*height[0] << endl;
        }
        else {
          tmp = bpi + bpj + height[0];
          tot += tmp*4;
          tot += 4*(bpii + bpjj);
          if (DBG) cout << "One on axis " << tmp << " " << bpii + bpjj << endl;
        }
      }
      else if (pts[i].second == 0 || pts[j].second == 0) {
        if (pts[i].second == 0 && pts[j].second == 0) continue;
        tot += (bpi + bpj)*4;
        tot += 4*(bpii + bpjj + height[0]);
        if (DBG) cout << "One on axis " << bpi+bpj << " " << bpii + bpjj + height[0]  << endl;
      }
      else {
        // Same quadrant
        if (j != i){
          tmp = bpi - bpj;
          if (tmp < 0) tmp = -tmp;
          if (pts[i].first*pts[j].second < pts[i].second*pts[j].first) {
            tmp -= polj;
          }
          else {
            tmp -= poli;
          }
          if (tmp < 0) tmp = 0;
          if (DBG) cout << "Same quad: " << tmp;
          tot += tmp*4;
        }

        // Adjacent quadrants
        tot += (i==j?4:8)*(bpi + bpj + height[0]);
        if (DBG) cout << "  Adj. quad: " << bpi + bpj + height[0];

        // Opposite quadrants
        if (j != i && pts[i].first*pts[j].second != pts[j].first*pts[i].second) {
          tmp = ptsinquad;
          if (ccw(mp(0,0), pts[i], pts[j]) < 0)
            tmp += bpj + bel[pts[i].second][pts[i].first];
          else
            tmp += bpi + bel[pts[j].second][pts[j].first];
          tot += tmp*4;
          if (DBG) cout << "  Opp. quad: " << tmp << endl;
        }
      }
      if (DBG) cout << " " << tot - ttot << endl;
    }
    if (DBG) cout << " = " << tot - tto << endl;
  }
  cout << tot/3 << endl;
  return 0;
}