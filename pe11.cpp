// pe11
#include <iostream>
#include <fstream>

using namespace std;

int grid[20][20];

int calcmp(int a, int b) {
  int prod = grid[a][b];
  int mp = 0;
  for(int i = -1; i <=1; i++) {
    for(int j = -1; j <=1; j++) {
      if (i == 0 && j == 0) continue;
      if (b + j*3 >= 20 || b + j*3 < 0) break;
      if (a + i*3 >= 20 || a + i*3 < 0) break;
      prod = grid[a][b];
      for(int k = 1; k < 4; k++) {
        prod *= grid[a+i*k][b+j*k];
      }
      if (prod > mp) mp = prod;
    }
  }
  return mp;
}

int main() {
  ifstream in("grid.txt");

  for(int i = 0; i < 20; i++) {
    for(int j = 0; j < 20; j++) {
      in >> grid[i][j];
    }
  }

  int maxprod = 0;
  for(int i = 0; i < 20; i++) {
    for(int j = 0; j < 20; j++) {
      int mp = calcmp(i, j);
      if (mp > maxprod) maxprod = mp;
    }
  }
  cout << maxprod << endl;
  return 0;
}
