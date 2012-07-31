#include <iostream>
#include <string>
#include <stack>
#define M 90

using namespace std;

int l = 100;
string a = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
string b = "8214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196";
/*string a = "1415926535";
string b = "8979323846";*/
long long fib[M];

char D(long long x, int n) {
    while(n > 1) {
        if (x < l*fib[n-2]) --n;
        else x -= l*fib[n-2];
        --n;
    }
    if (n == 1) return b[x-1];
    else if (n == 0) return a[x-1];
}

char Da(long long x) {
    int f = 0;
    while(fib[f]*l < x) {
        ++f;
    }
    return D(x, f);
}

int main() {
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i < M; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
        if (fib[i] < 0) {
            cout << "Overflow at fib " << i << endl;
            break;
        }
    }
    
    long long p7 = 1;
    stack<char> ans;
    for(int i = 0; i <=17; ++i) {
        long long x = (127 + 19*i)*p7;
        ans.push(Da(x));
        p7 *= 7; 
    }
    while (!ans.empty()) {
        cout << ans.top(); ans.pop();
    }
    cout << endl;
    cin.get();
    return 0;
}
