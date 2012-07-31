#include <iostream>
#include <vector>
#define MAX 1000000

using namespace std;

bool isprime[MAX];

vector<int> table[20];
int numpaths[MAX];

/*
 * Add path ending at (p2, p3) and path going through (p2, p3)
 */
void traverse(int p2, int p3, int sum) {
    int s = sum + table[p2][p3];
    if (s >= MAX) return;
    ++numpaths[s];  // Adding subpath ending at p2, p3 beginning at begin
    for(int i = p2-1; i >=0; --i) {
        for(int j = p3+1; j < table[i].size(); ++j) {
            traverse(i, j, s);
        }
    }
}

int main() {
    // Clear mem
    for(int i = 0; i < MAX; ++i) {
        numpaths[i] = 0;
        isprime[i] = true;
    }
    
    // Initialize table
    int p2 = 1;
    int p3 = 1;
    for(int i = 0; i < 20; ++i) {
        p3 = 1;
        for(int j = 0; j < 13 && p2*p3 < MAX; ++j) {
            table[i].push_back(p2*p3);
            cout << table[i][j] << " ";
            p3 *= 3;
        }
        cout << endl;
        p2 *= 2;
    }
    
    // Traverse table, starting from first row
    for(int i = 0; i < 20; ++i) {
        for(int j = 0; j < table[i].size(); ++j) {
            traverse(i, j, 0);
        }
    }
    cout << "Done" << endl;
    int tot = 0;
    for(int i = 2; i < MAX; ++i) {
        if(isprime[i]) {
            if (numpaths[i] == 1) tot += i;
            for(int j = 2*i; j < MAX; j += i) isprime[j] = false;
        }
    }
    cout << tot << endl;
    
    cin.get();
    return 0;
}
