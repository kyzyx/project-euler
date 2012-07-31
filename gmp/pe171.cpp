#include <iostream>
#include <vector>
#include <gmp.h>
#include <gmpxx.h>
#define NS 41
#define pb push_back
#define VI vector<int>
#define DIGITS 20

typedef mpz_class BigInt;

using namespace std;

int squares[NS];
VI reachable[20*81];
BigInt sum = 0;

BigInt facs[21];

void calc(int n, VI ns, int d, int m) {
    if (d == DIGITS || n == 0) {
        if (n != 0) return;

      	BigInt total = 1;
        for(int i = 1; i < 10; i++) {
        //    cout << ns[i] << " ";
        	total *= facs[ns[i]];
        }
        total *= facs[DIGITS-d];
        BigInt totadd = 0;
		//cout << " -> ";
		for(int i = 1; i < 10; i++) {
			if (ns[i] == 0) continue;
			BigInt add("11111111111111111111");
			add *= ns[i]*facs[DIGITS-1]*i/total;
			totadd += add;
		}
		//cout << totadd << endl;
		sum += totadd;
        return;
    }
    for(int i = 0; i < reachable[n].size(); i++) {
        if (reachable[n][i] > m) continue;
        //cout << "(" << n << "," << reachable[n][i] << ")" << endl;
        ++ns[reachable[n][i]];
        calc(n-squares[reachable[n][i]], ns, d+1, reachable[n][i]);
        --ns[reachable[n][i]];
    }
}


int main() {
    int M = 20*81;

    facs[0] = 1;
    for(int i = 1; i < 21; i++) {
        facs[i] = facs[i-1]*i;
    }

    for(int i = 0; i*i < M; i++) {
        squares[i] = i*i;
    }

    reachable[0].pb(0);

    for(int i = 1; i < 10; i++) {
        for(int k = 0; k < 20*81; k++) {
            if (reachable[k].size() != 0 && reachable[k].back() < i) {
                for(int j = 1; j < 20; j++) {
                    if(k+j*squares[i] < 20*81) reachable[k+j*squares[i]].pb(i);
                }
            }
        }
    }

    for(int i = 1; i < NS; i++) {
        calc(squares[i], vector<int>(10,0), 0, 9);
        //cin.get();
    }
    cout << sum%1000000000 << endl;
    cin.get();
    return 0;
}
