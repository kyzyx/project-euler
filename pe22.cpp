#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ifstream in("Inputs/names.txt");
    
    long long tot = 0;
    long long nt = 0;
    vector<string> names;
    string tmp;
    while (!in.eof()) {
        getline(in, tmp, '"');
        getline(in, tmp, '"');
        if (tmp == "") continue;
        names.push_back(tmp);
    }
    sort(names.begin(), names.end());
    
    for(int i = 0; i < names.size(); ++i) {
        //cout << i+1 << ": " << names[i] << " ";
        nt = 0;
        for(int j = 0; j < names[i].size(); ++j) {
            nt += names[i][j] - 'A' + 1;
        }
        //cout << nt << endl;
        tot += nt * (i+1);
    }
    cout << tot << endl;
    
    cin.get();
    return 0;
}
