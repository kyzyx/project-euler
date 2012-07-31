#include <iostream>
#define MAX 10000

using namespace std;

int sums[MAX];

int main() {
    for(int i = 1; i < MAX; ++i) sums[i] = 1;
    for(int i = 2; i < MAX; ++i) {
        for(int j = i*2; j < MAX; j += i) {
            sums[j] += i;
        }
    }
    
    int tot = 0;
    for(int i = 1; i < MAX; ++i) {
        if (sums[i] != i && sums[sums[i]] == i) tot += i;
    }
    cout << tot << endl;
    cin.get();
    return 0;
}
