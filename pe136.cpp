#include <iostream>
#define MAX 50000000
#define M 50000000
#define fori(n) for(int i = 0; i < n; i++)

using namespace std;

unsigned int sq[MAX];
unsigned int pos[M];
int z = 0;

int main() {
    fori(MAX) {
        sq[i] = i*i;
        pos[i] = 0;
    }
    for(int i = 0; i < MAX; i+=2) {
        for(int j = i; j >= 0; j--) {
            if(sq[i]-sq[j] > M) break;
            ++pos[sq[i]-sq[j]];
            if(j !=0 && i/2 - j > 0) ++pos[sq[i]-sq[j]];
        }
    }

    int tot = 0;
    for(int i = 0; i < M; i++) {
        if(pos[i] == 1){
             ++tot;
            //cout << i << endl;
        }
    }
    cout << "Total = " << tot << endl;
    cin.get();
    return 0;
}
