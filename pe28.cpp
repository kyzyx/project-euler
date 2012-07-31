#include <iostream>

using namespace std;

int main() {
    long long tot = 1;
    for(long long i = 3; i < 1002; i+=2) {
        tot += 4*(i*i - i + 1 - i/2);
    }
    
    cout << tot << endl;
    cin.get();
    return 0;
}
