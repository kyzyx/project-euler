#include <iostream>
#include <vector>
#include <cmath>
#define MAX 1000001

using namespace std;

bool isprime[MAX];
vector<int> primes;

unsigned long long numGrids(unsigned long long moves) {
    // 2x - 2 + d - get to base
    // 6x - 9     - get to corner
    // 3          - get to optimal, which leaves rect (d+1)*2 - 1, needing to be rotated d-1 times 5
    // 5(d-1)
    // ----------
    // 8x - 13 + 6d

    // 8x - 11         is p^2
    // 8x - 7          is p^2
    // 8x - 9 + 2d^2   is p^2
    unsigned long long cnt = 0;
    if (moves % 8 == 5) {
         ++cnt;
        //cout << (moves + 11) / 8 << "*" <<  (moves + 11) / 8 << endl;
    }
    else if (moves%8 == 1) {
        cnt += 2;
/*        cout <<'a' << (moves + 7) / 8 << "*" <<  (moves + 7) / 8 + 1 << endl;
        cout <<'a' << (moves + 7) / 8 + 1 << "*" <<  (moves + 7) / 8 << endl;*/
    }

    // moves = 8x - 13 + 6d
    // 8x = moves + 13 - 6d
    // k - 6d === 0 mod 8
    // 2 < d < k/6
    // 6d == k mod 8
    // k == 0: 4, 8, 
    // k == 2: 3, 7, 11, 
    // k == 4: 2, 6, 10
    // k == 6: 1, 5, 9
    
    // moves + 13 - 6d = 8x > 8
    unsigned long long k = moves + 13;
    unsigned long long lim = (moves + 5) / 6;
    if (((k%8)&1) == 0) {
        unsigned long long diff = lim - (4 - (k%8)/2) + 1;
        cnt += 2*((diff+3)/4);
        if (k%8 == 6) cnt -= 2; // d = 1 is not a solution
        if (((k-8)/6) % 4 == (4 - (k%8)/2) % 4) cnt -= 2; // x = 1 is not a solution
    }
    return cnt;
}

int main() {
    // Generate Primes
    for(int i = 0; i < MAX; ++i) isprime[i] = true;
    for(int i = 2; i < MAX; ++i) {
        if (isprime[i]) {
            primes.push_back(i);
            for(int j = 2*i; j < MAX; j+= i) isprime[j] = false;
        }
    }

    //cout << numGrids(41) << endl;

    unsigned long long cnt = 0;
    for(int i = 0; i < primes.size(); ++i) {
        // Check squares:
        unsigned long long sq = primes[i];
        sq *= sq;
        unsigned long long r = numGrids(sq);
        //cout << i << ": " << sq << ": " <<  r << endl;
        //if (i%100 == 0) cout << i << endl;
        cnt += r;
  //      cin.get();
    }

    cout << cnt << endl;
    cin.get();
    return 0;
}
