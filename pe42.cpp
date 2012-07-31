#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tri;

int main() {
    for(int i = 1; i < 100; ++i) {
        tri.push_back((i*i + i)/2);
    }
    long long ct = 0;
    ifstream in("Inputs/words.txt");
    char c;
    int tot = 0;
    while(!in.eof()) {
        in >> c;
        if (c == '"' ||c == ',') {
            if (binary_search(tri.begin(), tri.end(), tot)) ++ct;
            tot = 0;
            continue;
        }
        tot += c - 'A' + 1;
    }
    
    cout << ct << endl;
    cin.get();
    return 0;
}
