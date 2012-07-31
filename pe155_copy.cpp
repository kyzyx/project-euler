/* 0:50*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 19

using namespace std;

    bool cc(double a, double b) {
        if (a>b) return a - b < 1e-10;
        return b-a < 1e-10;
    }


vector<double> values[MAX];
vector<double> allvals;

int main(){
    values[1].push_back(1);
    for(int i=2; i<MAX; i++){
        for(int j=1; j<=i/2; j++){
            
            for (vector<double>::iterator it = values[j].begin(); it != values[j].end(); ++it) {
                for(vector<double>::iterator jt = values[i-j].begin(); jt != values[i-j].end(); ++jt) {
                    double a = (*it)+(*jt);
                    double b = (*it)*(*jt)/a;
                    values[i].push_back(a);
                    values[i].push_back(b);
                }
            }
            sort(values[i].begin(), values[i].end());
            vector<double>::iterator jt = unique(values[i].begin(), values[i].end(), cc);
            values[i].erase(
                jt,
                values[i].end()
            );
        }
        cout << i << ": " << values[i].size() << endl;
    }

    for(int i = 1; i < MAX-1; ++i) {
        values[MAX-1].insert(values[MAX-1].end(), values[i].begin(), values[i].end());
    }
    sort(values[MAX-1].begin(), values[MAX-1].end());
    vector<double>::iterator jt = unique(values[MAX-1].begin(), values[MAX-1].end(), cc);
    cout << jt - values[MAX-1].begin() << endl;
    cin.get();
    return 0;
}
