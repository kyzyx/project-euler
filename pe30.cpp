#include <iostream>

using namespace std;

bool works(int m) {
    int t = 0;
    int n = m;
    while(n > 0) {
        int d = n%10;
        t += d*d*d*d*d;
        n /= 10;
    }
    return t == m;
}

int main() {
    int tot = 0;
    for(int i = 2; i < 1000000; ++i) {
        if (works(i)) tot += i;
    }
    cout << tot << endl;
    cin.get();
    return 0;
}
