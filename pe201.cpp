// 11s
// Can be optimized by pruning subsets of more than 1
#include <iostream>
#define M 100
#define S 338351
#define T 50

using namespace std;

int e[M];
int n[S][M];
int m[T+1];

int main() {
    int s = 0;
    for(int i = 0; i < M; ++i) e[i] = (i+1)*(i+1);
    for(int i = 0; i < S; ++i) {
        for(int j = 0; j < M; ++j) n[i][j] = 0;
    }
    for(int i = 0; i < T+1; ++i) m[i] = 0;
    
    n[0][0] = 1;
    for(int i = 0; i < M; ++i) {
        for(int j = i>=T?T-1:i; j >= 0; --j) {
            for(int k = 0; k <= m[j]; ++k) {
                if (n[k][j]) {
                    n[k+e[i]][j+1] += n[k][j];
                    if (m[j+1] < k+e[i]) m[j+1] = k+e[i];
                }
            }
        }
    }
    
    for(int i = 0; i < S; ++i) {
        if (n[i][T] == 1) {
            s += i;
        }
    }
    
    cout << s << endl;
    
    cin.get();
    return 0;
}
