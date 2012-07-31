/* Answer involves convergents of sqrt(5) */
#include <iostream>
#include <vector>
#include <map>
#define MAX 40000
#define LL unsigned long long

using namespace std;

vector<pair<LL,LL> > x;
vector<LL > result;

/*
int cmp(pair<LL,LL> a, pair<LL,LL> b) {
    return (a.second - b.second);
}*/

int main() {
    // Calculate convergents - sqrt(5) = 2 + 1/(4+1/(4+...))
    x.push_back(make_pair(2UL,1UL));
    x.push_back(make_pair(9UL,4UL));
    int b = 4, a = 1;
    for(int i = 2; i < 23; i++) {
        pair<LL,LL> t1 = x[i-1], t2 = x[i-2];
        x.push_back(make_pair(b*t1.first+a*t2.first, b*t1.second+a*t2.second)); 
        LL a = 2*x[i].first; LL b = 2*x[i].second;
        if (((a - 1) %5 == 0) && a*a + 4 - 5*b*b == 0) {
            result.push_back(a);
        }
        cout << x[i].first << "/" << x[i].second << endl;
    }
    
    // calculate semiconvergents
    for(int i = 0; i < 21; i++) {
        LL a = x[i].first;
        LL b = x[i].second;
        for(LL j = 1; j < 2*x[i].second; j++) {
              a += x[i+1].first;
              b += x[i+1].second;
              cout << a << "/" << b << endl;
              if (a > x[i+2].first || b > x[i+2].second) break;
             if (((a - 1) %5 == 0) && a*a + 4 - 5*b*b == 0) {
                result.push_back(a);
             }   
        }
    }
    sort(result.begin(), result.end());
    // Transform into solution
    for(int i = 0; i < result.size(); i++) {
        if ((result[i] - 1) % 5) continue;
        cout << i << ":" << (result[i]-1)/5 << endl;
    }
    
    cin.get();
    return 0;
}
