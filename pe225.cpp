#include <iostream>
#include <set>
#define MAX 10000

using namespace std;

bool works(int a) {
    set<pair<int,int> > seqs[a];
    int x, y, z, tmp;
    x = y = z = tmp = 1;
    seqs[x].insert(make_pair(y, z));
    tmp = x+y;
    x = y;
    y = z;
    z += tmp;
    z %= a;
    while (seqs[x].find(make_pair(y,z)) == seqs[x].end()) {
        if (z == 0) return false;
        tmp = x+y;
        x = y;
        y = z;
        z += tmp;
        z %= a;
    }
    return true;
}

int main() {
    int n = 0;
    for(int i = 27; i < MAX; i+=2) {
        if (works(i)) {
            cout << ++n << ": " << i << endl;
        }
        if (n == 124) {
            break;
        }
    }


    cin.get();
    return 0;    
}
