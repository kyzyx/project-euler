#include <iostream>
#include <vector>
#define M 80

/*
 * First, notice that primes must cancel, e.g. 
 * 1/13^2 + 1/39^2 + 1/52^2 = (1/13^2)(1*9+1*16+9*16)/(1*9*16) = 1/144 (169 cancelled)
 *
 * Then, generate these for primes 7+. Since we can't cancel factors of 11,
 * only go up to 70 for 7. The only things that work are 1 for 13 and 19 for
 * 7, resulting in 40 total possibilities. 
 *
 * Also note that 2 must be one of the terms, since 1/3^2...1/80^2 < 0.5
 *
 * Then, construct all numbers composed of 2,3,5 (28 of them) and generate all
 * subsets of these 28. See if any of these plus any of the 40 subsums add to
 * 0.25. 
 *
 * Brute force checks 40*2^28 in 55s
 * Precomputing the first 16 bits in 32s
 */
using namespace std;

#define PROD 1866240000LL
long long ev(int set) {
    long long tot = 0;
    long long p = 1;
    vector<int> n;
    for (int i = 1; set; ++i) {
        if (set&1) {
            n.push_back(i*i);
            p *= i*i;
        }
        set >>= 1;
    }
    for (int i = 0; i < n.size(); ++i) {
        tot += p/n[i];
    }
    return tot;
}

int nums[100];
int nn = 0;
long long nd[100];
const int pcn = 16;
// Precompute 2^12 sums
long long precomp[1<<pcn];

void genNums() {
    for (int i = 1; i <= M; i *= 2) {
        for (int j = 1; j*i <= M; j*= 3) {
            for (int k = 1; j*k*i <= M; k *= 5) {
                if (i*j*k <= 2) continue;
                nums[nn++] = i*j*k;
            }
        }
    }
    for (int i = 0; i < nn; ++i) {
        nd[i] = PROD/(nums[i]*nums[i]);
    }
    for (int i = 0; i < (1<<pcn); ++i) {
        long long tot = 0;
        int t = i;
        for (int j = 0; t; ++j) {
            if (t&1) tot += nd[j];
            t >>= 1;
        }
        precomp[i] = tot;
    }
}

long long sum(int set) {
    long long tot = precomp[set & ((1<<pcn) - 1)];
    set >>= pcn;
    for (int i = pcn; set; ++i) {
        if (set&1) {
            tot += nd[i];
        }
        set >>= 1;
    }
    return tot;
}

long long setSum(int set, int f=1) {
    long long tot = ev(set)/(f*f);
    long long p = 1;
    for (int i = 1; set; ++i) {
        if (set&1) p *= i*i;
        set >>= 1;
    }
    while (tot%2==0 && p%2==0) {
        tot /= 2; p /= 2;
    }
    while (tot%3==0 && p%3==0) {
        tot /= 3; p /= 3;
    }
    while (tot%5==0 && p%5==0) {
        tot /= 5; p /= 5;
    }
    return (PROD/p)*tot;
}

long long ts[100];
int nts = 0;

int p[] = {7,11,13,17,19,23,29,31,37};
int np = 9;

int main() {
    genNums();
    int i = 0;
    //for (int i = 0; i < np; ++i) {
        for (int j = 0; j < (1<<(10)); ++j) {
            if (ev(j) % (p[i]*p[i]) == 0) {
                 ts[nts++] = setSum(j,p[i]);
                 ts[nts++] = setSum(j,p[i]) + setSum(13,13);
            }
        }
    //}
    long long count = 0;
    for (int j = 0; j < (1<<nn); ++j) {
        long long s = sum(j);
        for (int i = 0; i < nts; ++i) {
            if (s + ts[i] == PROD/4) {
                ++count;
                cout << j << endl;
            }
        }
    }
    cout << "Count: " << count << endl;
    return 0;
}
