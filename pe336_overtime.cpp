/* Dumb brute force - 1:05 
   Smart way - only generate worst case
   Given worst sol'n wxyz
   1. Prepend A
   2. Flip
   3. Flip each of n-2 positions
   */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define MAX 39916800
#define N 11
//#define MAX 720
//#define N 6

using namespace std;

string lexmap[MAX];
int nummoves[MAX];

char tmp[N+1];
int lim;
int facs[N];

int ind(string& s, int n) {
    int less = 0;
    for(int i = 0; i < n; ++i) {
        if (s[i] < s[n]) ++less;
    }
    return s[n] - 'A' - less;
}

int revmap(string& s) {
    // Calculate factorial base rep
    int ret = 0;
    for(int i = 0; i < N-1; ++i) {
        ret += facs[N-1-i]*ind(s, i);
    }
    return ret;
}

int cm(int n) {
    // Determine char to rotate
    if (nummoves[n] != -1) {
        return nummoves[n];
    }
    
    char a;
    for(a = 0; a < N; ++a) {
        if(lexmap[n][a] != a+'A') break;
    }
    if (a == N) {
        nummoves[n] = 0;
    }
    else {
        strcpy (tmp, lexmap[n].c_str());
        // Determine if we just need to rotate
        if (tmp[N-1] == a+'A') {
            lim = (N+a)/2;
            for(int i = a; i < lim; ++i) {
                swap(tmp[i], tmp[N-i+a-1]);
            }

        }
        else {
            // find index of a
            for(int i = a+1; i < N; ++i) {
                if (tmp[i] == a+'A') {
                    lim = (N+i)/2;
                    for(int j = i; j < lim; ++j) {
                        swap(tmp[j], tmp[N-j+i-1]);
                    }
                    break;
                } 
            }
        }

        string sss(tmp);
        nummoves[n] = cm(revmap(sss)) + 1;
        //cout << lexmap[n] << "->" << sss << " " << ": " << nummoves[n] << endl;
    }
    return nummoves[n];
}

int main() {
    char s[] = "ABCDEFGHIJK";
    //char s[] = "ABCDEF";
    lexmap[0] = string(s);

    facs[0] = 1;
    for(int i = 1; i < N; ++i) facs[i] = facs[i-1]*i;
    for(int i = 0; i < MAX; ++i) nummoves[i] = -1;
    nummoves[0] = 0;
    for(int i = 1; next_permutation(s, s+N); ++i) {
        lexmap[i] = s;
        if (i % 1000000 == 0) cout << i << endl;
        //cout << i << ": " << lexmap[i] << " : " << revmap(lexmap[i]) << endl;
    }
    cout << "-------------------------" << endl;
    cin.get();
    int mx = 0;
    int mxi = 0;
    int target = 2011;
    string best = "";
    for(int i = 1; i < MAX; ++i) {
        if (nummoves[i] == -1) {
            int tmp = cm(i);
            if (tmp > mx) {
                mx = tmp;
                mxi = 1;
                //cout << mxi << ": " << i << " " << lexmap[i] << ": " << mx << endl;
            }
            else if (tmp == mx) {
                ++mxi;
                //cout << mxi << ": " << i << " " << lexmap[i] << ": " << mx << endl;
                if (mxi == target) {
                    best = lexmap[i];
                    //break;
                }
            }
        }
        if (i % 500000 == 0) cout << i << endl;
    }
    cout << best << endl;
    cin.get();
    return 0;
}
