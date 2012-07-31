#include <iostream>

using namespace std;

bool works(long long t) {
    t /= 100;
    for(int i = 8; i >= 1; --i) {
        if (t%10 != i) return false;
        t /= 100;
    }
    return true;
}

int main() {
    for(long long i = 101010100; i < 138902660; i+=10) {
        if (works((i+3)*(i+3))) cout << i+3 << 0 << endl;
        else if (works((i+7)*(i+7))) cout << i+7 << 0 << endl;
    }

    cin.get();
    return 0;
}
