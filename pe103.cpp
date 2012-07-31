#include <iostream>
#include <vector>
#define N 7
#define MAX 35

using namespace std;

vector<int> best;
int sb = 99999999;

int sumv(vector<int>& arr, int n) {
    int sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        if (n%2) sum += arr[i];
        n >>= 1; 
    }
    return sum;
}

int check(vector<int>& arr) {
    int l = arr.size();
    vector<int> possible[300];
    for(int i = 0; i < 300; i++) possible[i] = vector<int>(0);
    int ts = 0;
    for(int i = 0; i < l; i++) ts += arr[i];
    for(int i = 1; i < 1 << (l+1); i++) {
        int k = sumv(arr, i);
        if(possible[k].size() != 0) {
            for(int j = 0; j < possible[k].size(); j++) {
                if ((i|possible[k][j]) == i+possible[k][j]) {
                    //cout << "Failed sum test: " << possible[k][j] << " " << i<< endl;
                    return 0;
                }
            }
        }
        possible[k].push_back(i);
    }
    

    if (ts < sb) {
        for(int i = 0; i < N; i++) cout << arr[i] << " ";
        cout << endl;
        sb = ts;

        //for(int i = 0; i < N; i++) best[i] = arr[i];
    }
    return ts;
}

void genNext(vector<int>& curr, int a) {
    int sumfront = 0;
    int sumback = 0;
    int nremaining = N - a*2 + 1;
    for(int i = 0; i < a; i++) {
        sumfront += curr[i];
        if (i != a-1) sumback += curr[N-i-1];
    }
    
    if (((N&1) == 0) && a == N/2 + 1) {
        for (int i = curr[N/2] + 1; i < curr[N/2+2]; i++) {
            curr[N/2+1] = i;
            check(curr);
        }
    }
    
    for(int i = curr[a-1] + 1; i <= curr[N-a+1] - nremaining; i++) {
        curr[a] = i;
        for(int j = curr[N-a+1] - 1; j >= i + nremaining - 1; j--) {
            if (j + sumback >= i + sumfront) continue;
            curr[N - a] = j;
            
            /*if (a == 3) {
            for(int z = 0; z < N; z++) {
                if (z <= a || z >= N-a) {
                    cout << curr[z] << " ";
                }
                else cout << "_ ";
            }
            cout << endl;
            cin.get();
            }*/
            
            if (a == N/2 + 1) {
                check(curr);
            }
            else{
                genNext(curr, a+1);
            }
        }
    }
} 

int main() {
    vector<int> curr(N);
    for(int i = 18; i < 25; i++) {
        for(int j = i+1; j < MAX; j++) {
            curr[0] = i; curr[1] = j;
            for(int k = i + j - 1; k >= j + N - 1; k--) {
                curr[N-1] = k;
                genNext(curr, 2);
            }
            //cout << i << " " << j << endl;
        }
    }
    cout << sb << ":";
    if (best.size() == N) for(int i = 0; i < N; i++) cout << best[i] << " ";
    cout << endl;
    cin.get();
}
