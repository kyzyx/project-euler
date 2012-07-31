#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> edges[30];
int cur=0;
int ord[30];
int visited[30];

void dfs(int a) {
    if (visited[a] == 1) {
        cout << a << " Cycle!" << endl;   
    }
    else if (!visited[a]) {
        visited[a] = 1;
        for(int i = 0; i < edges[a].size(); ++i) {
            dfs(edges[a][i]);
        }
        visited[a] = 2;
        ord[cur++] = a;
    }
}

bool isin[10];
int main() {
    ifstream in("Inputs/keylog.txt");
    char c;
    char d = '\n';
    
    for(int i = 0; i < 10; ++i) isin[i] = false;
    
    while(!in.eof()) {
        c = in.get();
        if (d != '\n' && c != '\n') {
            edges[d-'0'].push_back(c-'0');
            isin[d-'0'] = true;
            isin[c-'0'] = true;
        }
        d = c;
    }

    // Topo sort
    for(int i = 0; i < 30; ++i) visited[i] = 0;
    for(int i = 0; i < 10; ++i) {
        if (!isin[i]) continue;
        dfs(i);
    }
    for(int i = cur-1; i >= 0; --i) {
        cout << ord[i];
    }
    cout << endl;
    cin.get();
    return 0;
}
