#include <iostream>
#define MAX 1000000

using namespace std;

int main() {
    bool isprime[MAX];
    int np = 0;
    for(int i = 0; i < MAX; ++i) isprime[i] = true;
    for(int i = 2; i < MAX; ++i) {
        if (isprime[i]) {
            ++np;
            if (np == 10001) {
                cout << i << endl;
                break;
            }
            for(int j = 2*i; j < MAX; j += i) isprime[j] = false;
        }
    } 
    
    cin.get();
    return 0;
}
