#include <iostream>

using namespace std;

int main() {
    unsigned long n = 0;
    for(unsigned long i = 1; i <= (1 << 30); ++i) {
        if (((i ^ (i<<1)) ^ (3*i)) == 0) n++;
    }
    
    cout << n << endl;
    cin.get();
    
    return 0;
}
