/* Correct - just brute force / pattern for 9999 */
#include <iostream>
#include <queue>
#include <climits>
#define fori(n) for(int i = 0; i < n; i++)
#define forj(n) for(int j = 0; j < n; j++)
#define MAX 10000

using namespace std;

unsigned long long res[10];
unsigned long long pow10[18];

class result {
    public:
    unsigned long long n;
    unsigned long long f;
    int l;

    result() {
        f = 0; n = 0; l = 0;
    }
    result(unsigned long long nn, unsigned long long ff, int ll) {
        f = ff; n = nn; l = ll;
    }
};

bool works(unsigned long long n) {
    while(n>0) {
        if(n%10 >2) return false;
        n /= 10;
    }
    return true;
}

int main() {
    unsigned long long sum = 0;
    result r;

    pow10[0] = 1;
    for(int i = 1; i < 18; i++) pow10[i] = 10*pow10[i-1];

    //for(int z = 1; z <= MAX; z++) {
      //  if (z == 9999) continue;
    int z = 9999;
        queue<result> q;
        bool done = false;
        bool found = false;
        int ll = 0;
        unsigned long long best = ULLONG_MAX;
        fori(10) {
            res[i] = i*z;
            if(res[i]%10 <= 2 && i != 0) q.push(result(res[i]/10, i, 1));
        }
        while(!q.empty()) {
            r = q.front(); q.pop();
            if(found && r.l > ll) break;
            if(works(r.n)) {
                found = true;
                if (r.f < best) best = r.f;
                ll = r.l;
            }
            fori(10) {
                if((r.n+res[i])%10 <= 2) q.push(result((r.n+res[i])/10, r.f + pow10[r.l]*i , r.l+1));
            }
            cout << r.f << endl;
        }
        cout << z << ":" << best << endl;
        sum += best;
    //}

    cout << sum << endl;
    cin.get();
    return 0;
}
