// 22 seconds
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPD(long long a, long long b) {
    bool in[10];
    for (int i = 0; i < 10; ++i) in[i] = false;
    while (a > 0) {
        if (in[a%10]) return false;
        in[a%10] = true;
        a /= 10;
    }
    while (b > 0) {
        if (in[b%10]) return false;
        in[b%10] = true;
        b /= 10;
    }
    for (int i = 0; i < 10; ++i) {
        if (!in[i]) return false;
    }
    return true;
}

long long p10[10];
long long test(char* arr) {
    if (arr[0] == 0) return -1;
    long long best = 0;
    long long currn = 0;
    for (int i = 0; i < 8; ++i) {
        currn += arr[i];
        if (arr[i+1] != 0) {
            long long n1 = 0;
            for (int j = i+1; j < 9; ++j) {
                n1 += arr[j];
                if (arr[j+1] !=0) {
                    long long n2 = 0;
                    for (int k = j+1; k < 10; ++k) {
                        n2 += arr[k];
                        n2 *= 10;
                    }
                    n2 /= 10;
                    long long c1 = currn*n1;
                    long long c2 = currn*n2;
                    int l1 = log10(c1);
                    int l2 = log10(c2);
                    if (isPD(c1, c2)) {
                        long long cand;
                        if ((c1)/p10[l1] > (c2)/p10[l2]) { // currn*n1 first
                            cand = c1*p10[l2+1]+c2;
                        }
                        else {
                            cand = c2*p10[l1+1]+c1;
                        }
                        if (cand > best) best = cand;
                        //cout << currn << "*" << "(" << n1 << "," << n2 << ") = " << currn*n1 << "," << currn*n2 << "=" << cand << endl;
                    }
                }
                n1 *= 10;
            }
        }
        currn *= 10;
    }
    return best;
}

int main() {
    p10[0] = 1;
    for (int i = 1; i < 10; ++i) {
        p10[i] = 10*p10[i-1];
    }
    long long best = 0;
    char arr[] = {0,1,2,3,4,5,6,7,8,9};
    while (next_permutation(arr, arr+10)) {
        long long res = test(arr);
        if (res > best) best = res;
    }
    cout << best << endl;
    return 0;
}
