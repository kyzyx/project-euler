#include <iostream>

using namespace std;

bool isPower[101];

int numUnique(int n) {
    int P;
    int tmp = n*n;
    for (P = 1; tmp <= 100; tmp *= n, ++P) isPower[tmp] = true;
    
    bool used[P*100 + 1];
    int ret = 0;
    for(int i = 0; i < P*100 + 1; i++) used[i] = 0;
    for(int i = 2; i <= 100; i++) {
        for(int j = 1; j <= P; j++) {
            if (!used[i*j]) ++ret;
            used[i*j] = true;
        }
    }
    return ret;
}

int main(){
    for(int i = 0; i < 101; i++) isPower[i] = false;
    int total = 0;
    for(int i = 2; i <= 100; i++) {
        if (isPower[i]) {
            continue;
        }
        total += numUnique(i);
    }
    
    cout << total << endl;

    cin.get();
    return 0;   
}
