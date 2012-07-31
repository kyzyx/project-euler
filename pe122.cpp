#include <iostream>
#include <cmath>
#include <vector>
#define MAX 201
#define fori(n) for(int i = 0; i < n; i++)
#define forj(n) for(int j = 0; j < n; j++)

using namespace std;

vector<string> used[MAX];
int num[MAX];

int main() {
    fori(MAX) {
        num[i] = 999999;
        used[i].push_back(string(200, '\0'));
        used[i][0][1] = 1;
    }
    num[0] = 0;
    num[1] = 0;
    int total = 0;
    
    for(int i = 1; i < MAX; i++){
        for(int k = 0; k < used[i].size(); k++) {
            forj(MAX) {
                if(used[i][k][j] != '\0') {
                    if(i+j >= MAX) break;;
                    if(num[i+j] > num[i] + 1) {
                        num[i+j] = num[i]+1;
                        used[i+j].clear();
                        used[i+j].push_back(used[i][k]);
                        used[i+j][0][i+j] = 1;
                    }
                    else if(num[i+j] == num[i] + 1){
                        used[i+j].push_back(used[i][k]);
                        used[i+j][used[i+j].size()-1][i+j] = 1;
                    }
                }
            }
        }
        total += num[i];
        cout << i << ":" << num[i] << endl;;    
    }
    cout << total << endl;
    cin.get();
    return 0;
}
