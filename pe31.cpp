#include <iostream>

using namespace std;

int main() {
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
    int numways[201];
    for(int i = 0; i < 201; ++i) numways[i] = 0;
    numways[0] = 1;
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 201 - coins[i]; ++j) {
            if (numways[j] != 0) numways[j+coins[i]] += numways[j];
        }
    }
    cout << numways[200] << endl;
    
    cin.get();
    return 0;
}
