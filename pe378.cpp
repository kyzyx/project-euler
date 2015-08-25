// 45s using naive sieve and divisor table
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define N 60000001
#define M 1000000000000000000LL

using namespace std;

typedef long long ll;

class Node {
    public:
        Node(ll v) : val(v), count(1), l(NULL), r(NULL) {}
        ~Node() {
            if (l) delete l;
            if (r) delete r;
        }

        ll insertCount(ll v) {
            ll ret = 0;
            if (v > val) {
                ret += count - sz(r);
                if (r) ret += r->insertCount(v);
                else r = new Node(v);
            } else if (v < val) {
                if (l) ret += l->insertCount(v);
                else l = new Node(v);
            } else {
                ret += sz(l);
            }
            count++;
            return ret;
        }

    private:
        static ll sz(Node* n) {
            return n?n->count:0;
        }

        Node* l;
        Node* r;
        ll val;
        ll count;
};

void smallerleft(vector<ll>& a, vector<ll>& s) {
    Node* root = new Node(a[0]);
    s[0] = 0;
    for (int i = 1; i < a.size(); i++) {
        s[i] = root->insertCount(a[i]);
    }
}

void smallerright(vector<ll>& a, vector<ll>& s) {
    vector<ll> aa(a.size());
    copy(a.begin(), a.end(), aa.begin());
    reverse(aa.begin(), aa.end());
    smallerleft(aa, s);
    reverse(s.begin(), s.end());
}
void largerleft(vector<ll>& a, vector<ll>& s) {
    vector<ll> aa(a.size());
    ll maxa = *max_element(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        aa[i] = maxa - a[i];
    }
    smallerleft(aa, s);
}

using namespace std;

int isprime[N+1];
vector<int> primes;

int main() {
    for(int i = 0; i < N+1; ++i) isprime[i] = -1;
    for(int i = 2; i < N+1; ++i) {
        if (isprime[i] == -1) {
            primes.push_back(i);
            for(int j = i; j < N+1; j += i) isprime[j] = i;
        }
    }
    cout << "Done generating primes" << endl;

    vector<ll> T(N+1);
    ll last = 1;
    T[0] = 0;
    for(int i = 2; i <= N+1; ++i) {
        int tot = 1;
        int n = i;

        int nf = 0;
        int nfacs[8];
        int ncounts[8];
        char nmap[8];
        memset(nfacs, 0, 8*sizeof(int));
        memset(ncounts, 0, 8*sizeof(int));

        int cp = isprime[n];
        nfacs[nf] = cp;
        while (isprime[n] > 0) {
            ncounts[nf]++;
            n /= cp;
            if (isprime[n] != cp && isprime[n] > 0) {
                cp = isprime[n];
                nfacs[nf++] = cp;
            }
        }
        if (cp == 2) ncounts[nf]--;
        nf++;

        int nd = 1;
        for (int j = 0; j < nf; j++) {
            nd *= ncounts[j]+1;
        }

        T[i-1] = nd*last;
        last = nd;
    }
    T.resize(N);

    vector<ll> T2(N);
    largerleft(T, T2);
    vector<ll> T3(N);
    smallerright(T, T3);

    ll tot = 0;
    /*
    for (int i = 0; i < N; i++) {
        cout << i <<" " << T[i] << " " << T2[i] << " " << T3[i] << endl;
    }*/
    for (int i = 0; i < N-1; i++) {
        tot = (tot + T2[i] * T3[i]) % M;
    }

    cout << tot << endl;
}
