#include <iostream>
#include <algorithm>

using namespace std;

int d[] = {0,1,2,3,4,5,6,7,8,9};

int main() {
    for(int i = 1; i < 1000000; ++i) {
        next_permutation(d, d+10);
    }
    for(int i = 0; i < 10; ++i) cout << d[i];
    cout << endl;
    cin.get();
    return 0;
}
