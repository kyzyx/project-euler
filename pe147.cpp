#include <iostream>
#define M 47
#define N 43

using namespace std;

int rects[M][N][M][N];
int dgs[M+1][N+1][M+N][M+N];

bool allowed(int r, int c, int i, int j) {
  int ri = j; int rj = r+c-i;
  return i+j >= c && i + j < c + 2*r - 1 &&
         ri+rj > r && ri + rj <= r + 2*c - 1;
}


void cdiags(int r, int c) {
  bool ok[r+c][r+c];
  int forbidden[r+c][r+c];
  for(int i = 0; i < r+c; ++i) {
    for(int j = 0; j < r+c; ++j) {
      ok[i][j] = allowed(r, c, i, j);
      if (!ok[i][j]) forbidden[i][j] = 1;
      else forbidden[i][j] = 0;
      if (j > 0) forbidden[i][j] += forbidden[i][j-1];
    }
  }
  for(int i = 1; i < r+c; ++i) {
    for(int j = 0; j < r+c; ++j) {
      forbidden[i][j] += forbidden [i-1][j];
    }
  }
  for(int x = 0; x < r+c; ++x) {
  for(int y = 0; y < r+c; ++y) {
  int ret = 0;
  for(int i = 0; i < r+c-x; i++) {
    int j = 0;
    while(!ok[i][j] && j < r+c-y) ++j;
    //cout << i << "," << j << ": ";
    for(; ok[i][j] && j < r+c-y; ++j) {
      if (forbidden[i-1][j-1] + forbidden[i+x][j+y] -
          forbidden[i+x][j-1] - forbidden[i-1][j+y] == 0) {
        ++ret;
        //cout << "(" << i << "," << j << ") ";
      }
    }
    //cout << endl;
  }
  dgs[r][c][x][y] = ret;
  }
  }
}
int main() {
  // Rectangles
  unsigned long long tot = 0;
  for(int i = 0; i < M; ++i) {
    for(int j = 0; j < N; ++j) {
      int tr = 0;
      int td = 0;
      cdiags(i+1, j+1);
      for(int k = 0; k <= i; k++) {
        for(int l = 0; l <= j; l++) {
          rects[i][j][k][l] = (i-k+1)*(j-l+1);
          tr += rects[i][j][k][l];
          tot += (i-k+1)*(j-l+1);
        }
      }
      for(int k = 0; k < i+j; ++k) {
        for(int l = 0; l < i+j; ++l) {
          td += dgs[i+1][j+1][k][l];
          tot += dgs[i+1][j+1][k][l];
        }
      }
      cout << i+1 << " x " << j+1 << ": " << tr << " " << td << endl;
    }
  }
cout << tot << endl;
  return 0;
}

// 41s
