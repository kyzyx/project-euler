#include <iostream>

using namespace std;

int main() {
    int a = 0;
    int b = 0;
    for(int i = 1; i < 101; ++i) {
        a += i;
        b += i*i;
    }
    cout << a*a - b << endl;
    cin.get();
    return 0;
}
