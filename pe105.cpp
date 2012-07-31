#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> possible[20000];

int sumv(vector<int>& arr, int n) {
    int sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        if (n%2) sum += arr[i];
        n >>= 1; 
    }
    return sum;
}

vector<int> getarr(string s) {
    vector<int> ret;
    int tmp;
    while(s != "") {
        int n;
        sscanf(s.c_str(), "%d ", &n);
        ret.push_back(n);
        int l = s.find(",");
        if (l == string::npos) break;
        else l++;
        s = s.substr(l);
    }
    return ret;
}

int isSS(vector<int>& arr) {
    for(int i = 0; i < 20000; i++) possible[i] = vector<int>(0);
    sort(arr.begin(), arr.end());
    int l = arr.size();

    // Check S(B) < S(C), |B| < |C|
    int isum = arr[0], fsum = 0;
    for(int i = 0; i < l/2; i++) {
        isum += arr[i+1]; 
        fsum += arr[l-i-1];
        if (isum < fsum) {
            cout << "Failed subset sum test" << endl;
            return 0;
        }
    }
    int ts = 0;
    for(int i = 0; i < l; i++) ts += arr[i];
    for(int i = 1; i < 1 << (l+1); i++) {
        int k = sumv(arr, i);
        /*if (k == 240) {
            int q = i;
            for(int j = 0; j < arr.size(); j++) {
                if (q % 2) cout << arr[j] << " ";
                q >>= 1;
            }
            cout << endl;
            cout << i << ":" << k << " ";    
        }*/
        
        if(possible[k].size() != 0) {
            for(int j = 0; j < possible[k].size(); j++) {
                if ((i|possible[k][j]) == i+possible[k][j]) {
                    cout << "Failed sum test: " << possible[k][j] << " " << i<< endl;
                    return 0;
                }
            }
        }
        possible[k].push_back(i);
    }
    return ts;
}

int main() {
    ifstream in("sets.txt");
    int sum = 0;
    string str;

    for(int z = 0; z < 100; z++) {
        getline(in, str);
        vector<int> arr = getarr(str);
        sum += isSS(arr);
        cout << sum << endl;
    }
    cin.get();
    return 0;
}
