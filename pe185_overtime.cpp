/* Completes in 3:55 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#define L 16

using namespace std;

vector<string> n;
vector<int> c;
int N;

bool checkguess(int which, int m) {   
    for(int i = 0; i < which; i++) {
        if (n[i][m] == n[which][m]) return false;
    }
    return true;
}

void printguess(vector<char>& correct) {
    for(int i = 0; i < L; i++) {
        cout << correct[i];
    }
    cout << endl;
}

bool prune(vector<char>& correct, int which) {
    int counts[N];
    for(int i = 0; i < N; i++) counts[i] = 0;
    for(int j = 0; j < L; j++) {
        if (correct[j] == 'a') continue;
        for(int i = which+1; i < N; i++) {
            if (n[i][j] == correct[j]) {
                if (counts[i] == c[i]) return false;
                else ++counts[i];
            }
        }
    }
    return true;
}

void guess(vector<char>& correct, int which) {
    if (which == N) {
        cout << "***";
        printguess(correct);
        return;
    }
    /*if (which > 5) {
        if (!prune(correct, which)) return;
    }*/
    //printguess(correct);
    int numtoguess = c[which];
    for(int i = 0; i < L; i++) {
        if (correct[i] == n[which][i]) {
            --numtoguess;
        }
    }
    if (numtoguess == 0) {
        guess(correct, which+1);
        return;
    }
    if (numtoguess < 0) return;
    for(int i = 0; i < L; i++) {
        if (correct[i] != 'a' || !checkguess(which, i)) continue;
        // If this guess is consistent with past guesses
        correct[i] = n[which][i];
        if (which == 2) printguess(correct);
        if (numtoguess > 1) {
            for(int j = i+1; j < L; j++) {
                if (correct[j] != 'a' || !checkguess(which, j)) continue;
                correct[j] = n[which][j];
                if (numtoguess == 3) {
                    for(int k = j+1; k < L; k++) {
                        if (correct[k] != 'a' || !checkguess(which, k)) continue;
                        correct[k] = n[which][k];
                        guess(correct, which+1);
                        correct[k] = 'a';
                    }
                }
                else {
                    guess(correct, which+1);
                }
                correct[j] = 'a';
            }
        }
        else {
            guess(correct, which+1);
        }
        correct[i] = 'a';
    }
}

bool works(char* cs) {
    for(int i = 0; i < N; i++) {
        int nright = 0;
        for(int j = 0; j < L; j++) {
            if (cs[j] == n[i][j]) nright++;
        }
        if (nright != c[i]) return false;
        //else cout << i << endl;
    }
    return true;
}

int main() {
    ifstream in("nm.txt");
    
    // Assume I presorted it by c
    string tn; int tc;
    in >> N;
    for(int i = 0; i < N; i++) {
        in >> tn >> tc;
        n.push_back(tn);
        c.push_back(tc);
        cout << n[n.size() -1] << " " << c[c.size() - 1] << endl;
    }
    cin.get();
    vector<char> correct(L, 'a');
    guess(correct, 1);
    cin.get();

    char guess[] = "464026157184a533";
    for(char c = '0'; c <= '9'; c++) {
        guess[12] = c;
        cout << guess;
        if (works(guess)) cout << "***";
        cout << endl;
    }
    
    cin.get();
    return 0;
}
