#include <iostream>
#include <queue>
#define MAX 1048575
#define MOD 100000007

using namespace std;

// B = 0; R = 1
// Start state: 0 0100110011001100 = 19660
// Goal state:  0 0010010110100101 =  9637

int start = 19660;
int goal =   9637;

queue<int> state;
queue<int> dist;
queue<unsigned long long> checksum;
queue<string> st;

queue<string> sols;

int shortest = -1;
unsigned long long ans = 0;

bool visited[MAX];
int firstvisited[MAX];

void printState(int n) {
    int pos = n >> 16;
    for(int i = 0; i < 16; i++) {
        if (i == pos) cout << 'X';
        else if ((n>>(15-i))&1) cout << '1';
        else cout << '0';
        if (i % 4 == 3) cout << endl;
    }
}

void addNext(int n, int d, int s, string path) {
    if (visited[n]) {
        if (firstvisited[n] != d) {
            return;
        }
    }
    visited[n] = true;
    firstvisited[n] = d;
    if (n == goal) {
        if (shortest < 0) shortest = d;
        ans += s;
        sols.push(path);
        cout << path << " " << s << endl;
    }
    else {
        state.push(n);
        dist.push(d);
        checksum.push(s);
        st.push(path);
    }
}

void addNext2(int p, int n, int d, int sum) {
    //cout << p << " " << n << " " << d << endl;
    if (visited[n]) {
        if (firstvisited[n] == d) {
            visited[n] += visited[p];
        }
        return;
    }
    visited[n] = visited[p];
    firstvisited[n] = d;
    if (n == goal) {
        if (shortest < 0) shortest = d;
    }
    else {
        state.push(n);
        dist.push(d);
    }
    /*printState(n);
    cout << d << endl;
    cin.get();*/
}

int mv(int p1, int p2, int state) {
    // set p2 to 0; set p1=0 to p2;
    state &= 0xFFFF;
    int m1 = 0xFFFF - (1 << (15 - p2)); // ((state >> (15 - p1)) & 1)
    int b2 = (state >> (15 - p2)) & 1;
    int m2 = b2 << (15 - p1);
    return ((state & m1) | m2);
}

unsigned long long check(string s) {
    unsigned long long ret = 0;
    for(int i = 0; i < s.size(); i++) {
        ret = ret*243 + s[i];
        ret %= MOD;
    }
    return ret;
}

int main() {
    for(int i = 0; i < MAX; i++) {
        visited[i] = 0;
        firstvisited[i] = -1;
    }
    
    visited[start] = 1;
    firstvisited[start] = 0;
    
    cout << check("LULUR") << endl;
    
    printState(start);
    printState(goal);
    
    dist.push(0);
    state.push(start);
    checksum.push(0);
    st.push("");

    while(!state.empty()) {
        int ss = state.front(); state.pop();
        int dd = dist.front(); dist.pop();
        unsigned long long uu = checksum.front(); checksum.pop();
        string cs = st.front(); st.pop();
        
        int next;
        int pos = ss>>16;
        
        if (shortest > 0 && dd > shortest) break; 
        
        // D
        if (pos > 3) {
            next = ((pos - 4) << 16) | mv(pos, pos-4, ss);
            addNext(next, dd+1, (uu*243 + 'D')%MOD, cs + 'D');
        }
        
        // U
        if (pos < 12) {
            next = ((pos + 4) << 16) | mv(pos, pos+4, ss);
            addNext(next, dd+1, (uu*243 + 'U')%MOD, cs + 'U');
        }
        
        // R
        if (pos % 4) {
            next = ((pos - 1) << 16) | mv(pos, pos-1, ss);
            addNext(next, dd+1, (uu*243 + 'R')%MOD, cs + 'R');
        }
        
        // L
        if (pos % 4 != 3) {
            next = ((pos + 1) << 16) | mv(pos, pos+1, ss);
            addNext(next, dd+1, (uu*243 + 'L')%MOD, cs + 'L');
        }
    }
    
    unsigned long long aa = 0;
    while(!sols.empty()) {
        aa += check(sols.front());
        sols.pop();
    }
    //cout << shortest << " is the smallest number of moves; " << visited[goal] << " ways of getting to goal" << endl;
    cout << ans << " " << aa%MOD << endl;
    cin.get();
    return 0;
}
