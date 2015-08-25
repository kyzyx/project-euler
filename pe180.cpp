#include <iostream>
#include <vector>
#include <set>
#include "frac.h"
#define M 35
#define L 5000

using namespace std;

vector<int> triples;

int main() {
    frac s;
    vector<int> issq(L*L+1, 0);
    set<frac> sums;
    for (int i = 0; i <= L; i++) issq[i*i] = i;
    frac cs[2];
    frac c2s[2];
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j < i; j++) {
            for (int k = 1; k <= M; k++) {
                for (int l = 1; l < k; l++) {
                    frac a(j, i);
                    frac b(l, k);
                    cs[0] = a + b;
                    cs[1] = (a.reciprocal() + b.reciprocal()).reciprocal();
                    c2s[0] = (a*a) + (b*b);
                    c2s[1] = ((a*a).reciprocal() + (b*b).reciprocal()).reciprocal();
                    for (int x = 0; x < 2; x++) {
                        if (cs[x].num < cs[x].den && cs[x].den <= M) {
                            sums.insert(a+b+cs[x]);
                        }
                        if (issq[c2s[x].num] && issq[c2s[x].den]) {
                            frac c(issq[c2s[x].num], issq[c2s[x].den]);
                            if (c.num < c.den && c.den <= M) {
                                sums.insert(a+b+c);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << sums.size() << endl;
    set<frac>::iterator it;
    for (it = sums.begin(); it != sums.end(); it++) {
        s = s + *it;
    }

    s.print();
    cout << endl;
    cout << s.den + s.num << endl;
}
