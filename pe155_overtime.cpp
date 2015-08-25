/* 3:40*/
#include <iostream>
#include <set>
#include "frac.h"
#define MAX 19

using namespace std;

struct cc {
    bool operator()(const frac& a, const frac& b) {
        frac tmp = a/b;
        return tmp.num < tmp.den;
    }
};

set<frac,cc> values[MAX];
set<frac,cc> allvals;

int main(){
    allvals.insert(frac(1,1));
    values[1].insert(frac(1,1));
    for(int i=2; i<MAX; i++){
        for(int j=1; j<=i/2; j++){
            for (set<frac>::iterator it = values[j].begin(); it != values[j].end(); ++it) {
                for(set<frac>::iterator jt = values[i-j].begin(); jt != values[i-j].end(); ++jt) {
                    frac a = (*it)+(*jt);
                    frac b = (*it)*(*jt)/a;
                    if (allvals.find(a) == allvals.end()) {
                        values[i].insert(a);
                        allvals.insert(a);
                    }
                    if (allvals.find(b) == allvals.end()) {
                        values[i].insert(b);
                        allvals.insert(b);
                    }
                }
            }
        }
        cout << i << ": " << values[i].size() << endl;
    }

    cout << allvals.size() << endl;
    cin.get();
    return 0;
}
