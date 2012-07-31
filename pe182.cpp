/*
a^phi = 1 for all a
Let p be a prime factor of phi
for some m, a^p = 1   (Check programmatically)
So for any b=kp+1, a^b=a
There is no exponent with no unconcealed message: 
    e=phi is even
    All candidates c must be odd
    But c-1 is even and so for any a^2 = 1, a^c = a
Therefore, find the prime with the fewest plaintext messages
    2 3
    3 8
    7 6
    607 606
Now, let the candidates be c
If c-1 has exactly one factor of 2, no factors of 3,7,607, then there will be 6 
(the three calculated plus n-1, 1 and 0) unconcealed messages. 
*/
#include <iostream>
#include <fstream>
#include <vector>
#define p 1009
#define q 3643

using namespace std;
typedef long long ll;

int n = p*q;
int e = (p-1)*(q-1);

ll powmod(ll a, ll b, ll m) {
    ll r = 1;
    ll pp = a;
    while (b>0) {
        if(b&1) r = (r*pp)%m;
        pp = (pp*pp)%m;
        b >>=1;
    }
    return r;
}

ll gcd(ll a, ll b) {
    if (b>a) return gcd(b,a);
    while(b>0) {
        ll tmp = a;
        a = b;
        b = tmp%b;
    }
    return a;
}

int main() {
    /*
    // Factors of e are 2,3,7,607
    int pr[] = {2,3,7,607};
    int t[4];
    for(int i = 0; i < 4; ++i) t[i] = 0;
    for(int i = 0; i < 4; ++i) {
        for(int j = 2; j < n; ++j) {
            if (powmod(j, pr[i], n) == 1) ++t[i];
        }
        cout << pr[i] << ": " << t[i] << endl;
    }
    cin.get();*/

    ll sum = 0;
    for(int i = 5; i < e; i+=2) {
        if (i%3 == 0 || i%7==0 || i%607 == 0) continue;
        if ((i-1)%4==0 || (i-1)%3==0 || (i-1)%7==0 || (i-1)%607==0) continue;
        sum += i;
    }
    cout << sum << endl;
    cin.get();
    return 0;
}
