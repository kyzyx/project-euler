#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int rot(int n) {
    int ret = n&31;
    ret <<= 1;
    ret |= ((n>>5)&1)^(((n>>4)&1) & ((n>>3)&1));
    return ret;
}

vector<int> edges[64];
int comp[64];

int main() {
    int z = 0;
    for(int i = 0; i < 64; i++) comp[i] = -1;
    for(int i = 0; i < 1<<6; ++i) {
        int j = rot(i);
        edges[i].push_back(j);
        edges[j].push_back(i);         
    }
    
    //bfs on graph to find components
    for(int i = 0; i < 64; i++) {
        if (comp[i] != -1) continue;
        comp[i] = z;
        
        queue<int> q;
        q.push(i);
        while(!q.empty()) {
            int j = q.front(); q.pop();
            for(int k = 0; k < edges[j].size(); k++) {
                if (comp[edges[j][k]] != -1) {
                    if (comp[edges[j][k]] != z) cout << "shit" << endl;
                    continue;
                }
                comp[edges[j][k]] = z;
                q.push(edges[j][k]);
            }
        }
        ++z;
    }
    int count[z];
    for(int i = 0; i < z; i++) count[i] = 0;
    for(int i = 0; i < 64; i++) {
        cout << i << "," << rot(i) << ": " << comp[i] << endl;
        count[comp[i]]++;
    }
    
    unsigned long long numRings[50][4];
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 50; j++) {
            numRings[j][i] = 0;
        }
    }
    numRings[1][0] = 1;
    numRings[1][3] = 1;
    // 0 - starts 0, ends 0
    // 1 - starts 0, ends 1
    // 2 - starts 1, ends 0
    // 3 - starts 1, ends 1
    for(int i = 2; i < 50; i++) {
        numRings[i][0] = numRings[i-1][0] + numRings[i-1][1];
        numRings[i][1] = numRings[i-1][0];
        numRings[i][2] = numRings[i-1][2] + numRings[i-1][3];
        numRings[i][3] = numRings[i-1][2];
        cout << i << ": " << numRings[i][0] << " " << numRings[i][1] << " " << numRings[i][2] << " " << numRings[i][3] << endl;
    }

    unsigned long long res = 1;
    for(int i = 0; i < z; i++) {
        unsigned long long tmp = numRings[count[i]][0] + numRings[count[i]][1] + numRings[count[i]][2];
        res *= numRings[count[i]][0] + numRings[count[i]][1] + numRings[count[i]][2];
        cout << count[i] << ": " << tmp << endl;
    }
    
    cout << res << endl;
    cin.get();
    return 0;
}
