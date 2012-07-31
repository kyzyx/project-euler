#include <iostream>
#include <vector>
#define maxi(a,b) (a>b?a:b)

using namespace std;

void outgrid(int g[4][4]) {
    for(int i = 0; i < 4;i++) {
        for(int j = 0; j < 4; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool checkgrid(int g[4][4]) {
    int s[10];
    for(int i = 0; i < 10; i++) s[i] = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            s[j]   += g[j][i];
            s[j+4] += g[i][j];
        }
        s[8] += g[i][i];
        s[9] += g[i][3-i];
    }
    for(int i = 1; i < 10; i++) {
        if (s[i] - s[0] != 0) return false;
    }
    return true;
}

/* Given first two rows and bottom quarter, select all possible a and fill in:
xxxx
xxxx
xx--
xx-a
*/
int works(int grid[4][4], int sum) {
    int s1 = grid[0][0] + grid[1][1];
    int s2 = grid[3][0] + grid[3][1];
    int s3 = grid[0][3] + grid[1][3];
    int ms = maxi(s1, s2);
    ms = maxi(ms, s3);
    if (ms > sum) return 0;
    int ret = 0; 
    for(int i = 0; i < 10 && i <= sum - ms; i++) {
        grid[3][3] = i;
        grid[3][2] = sum - s2 - i;
        if (grid[3][2] < 0 || grid[3][2] > 9) continue;
        grid[2][3] = sum - s3 - i;
        if (grid[2][3] < 0 || grid[2][3] > 9) continue;
        grid[2][2] = sum - s1 - i;
        if (grid[2][2] < 0 || grid[2][2] > 9) continue;
        if (checkgrid(grid)) {
            ++ret;
        }
    }
    return ret;
}

/* Given first two rows, select all possible a and fill in:
xxxx
xxxx
ac--
bd--
*/
int numways(int a, int b) {
    int grid[4][4];
    int sum = 0;
    int ret = 0;
    for(int i = 0; i < 4; i++) {
        grid[0][3-i] = a%10;
        grid[1][3-i] = b%10;
        sum += a%10;
        a /= 10; b /= 10;
    }
    for(int i = 0; i < 10 && i <= sum - grid[0][0] - grid[1][0]; i++) {
        grid[2][0] = i;
        grid[3][0] = sum - grid[0][0] - grid[1][0] - i;
        if (grid[3][0] > 9) continue;
        grid[2][1] = sum - grid[0][3] - grid[1][2] - grid[3][0];
        if (grid[2][1] < 0 || grid[2][1] > 9) continue;
        grid[3][1] = sum - grid[0][1] - grid[1][1] - grid[2][1];
        if (grid[3][1] < 0 || grid[3][1] > 9) continue;
        grid[3][2] = grid[3][3] = grid[2][2] = grid[2][3] = 0;
        //outgrid(grid);
        ret += works(grid, sum);
    }
    return ret;
}

// Select all possible first two rows
/*
xxxx
xxxx
----
----
*/
unsigned long long select(vector<int>& pos) {
    unsigned long long ret = 0;
    for(int i = 0; i < pos.size(); i++) {
        for(int j = 0; j < pos.size(); j++) {
            //cout << pos[i] << ", " << pos[j] << endl;
            unsigned long long tmp = numways(pos[i], pos[j]);
            ret += tmp;
        }
    }
    return ret;
}

int sum(int i) {
    int ret = 0;
    while(i > 0) {
        ret += i%10; 
        i/=10;
    }
    return ret;
}

int main() {
    vector<int> nums[37];
    for(int i = 0; i < 10000; i++) {
        nums[sum(i)].push_back(i);
    }
    
    
    unsigned long long tot = 0;
    for(int i = 0; i < 37; i++) {
        unsigned long long tmp = select(nums[i]);
        tot += tmp;
        cout << i << ": " << tmp << endl;
        //cin.get();
    }
    cout << tot << endl;
    
    cin.get();
    return 0;
}
