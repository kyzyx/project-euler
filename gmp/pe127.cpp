#include <iostream>
#include <vector>
#include <algorithm>
#include <gmp.h>
#include <gmpxx.h>
//#define MAX 1000
#define MAX 120000
#define fori(n) for(int i = 0; i < n; i++)
#define PII pair<unsigned int, unsigned int>

using namespace std;
typedef mpz_class BigInt;

int isprime[MAX+1];
int works[MAX+1];
unsigned int rad[MAX+1];
vector<int> primes;
vector<PII> sortrad;
vector<int> nextrad;

int main() {
    fori(MAX+1) isprime[i] = -1;
    fori(MAX+1) works[i] = -1;
    fori(MAX+1) rad[i] = 1;
    for(int i = 2; i < MAX+1; i++) {
        if (isprime[i] < 0) {
            for(int j = i*2; j < MAX+1; j+=i) {
                if(isprime[j] < 0) isprime[j] = primes.size();
                rad[j] *= i;
            }
            primes.push_back(i);
            isprime[i] = -primes.size();
            rad[i] = i;
            if (i > 400) continue;
            for(int j = i*i; j < MAX+1; j += i*i) {
                if(works[j] < 0) works[j] = primes.size()-1;
            }
        }
    }
    for(int i = 1; i < MAX+1; i++) {
        sortrad.push_back(make_pair(rad[i], i));
    }
    nextrad = vector<int>(sortrad.size());
    stable_sort(sortrad.begin(), sortrad.end());
    int lastindex = sortrad.size();
    nextrad[sortrad.size()-1] = sortrad.size();
    for(int i = sortrad.size()-2; i >= 0; i--) {
        if (sortrad[i].first != sortrad[i+1].first) {
            lastindex = i+1;
        }
        nextrad[i] = lastindex;
    }
    cout << "Done preprocess" << endl;
    int total = 0;
    
    for(int i = 2; i < MAX; i++) {
        if (i%5000 == 0) cout << i << endl;
        if (works[i] < 0) continue;
        int n = i;
        int p = 1;
        vector<bool> used(primes.size(),false);        
        // Factoring
        while (works[n] >= 0 && n != 1) {
            used[works[n]] = true;
            int cp = primes[works[n]];
            while(n%cp == 0) {
                 n /= cp;
                 p *= cp;
            }
            p /= cp;
        }
        while(n != 1 && isprime[n] >= 0) {
            used[isprime[n]] = true;
            n /= primes[isprime[n]];
        }
        
        // Gives all possible prime factors of ab
        //vector<int> candidates;
        BigInt product = 1;
        for(int j = 0; j < primes.size() && primes[j] < p; ++j) {
            if (used[j]) continue;
            //candidates.push_back(primes[j]);
            product *= primes[j];
        }
        
        for(int j = 0; sortrad[j].first < p; j++) {
            if (product % sortrad[j].first != 0 || sortrad[j].second > i/2) {
                j = nextrad[j] - 1;
            }
            else {
                if (product % (rad[i-sortrad[j].second]*sortrad[j].first) == 0 && rad[i-sortrad[j].second]*sortrad[j].first < p) {
    //                cout << i << " = " << sortrad[j].second << " + " << i-sortrad[j].second << endl;
                    total += i;
                }
            }
        }
    }
    cout << total <<endl;
    cin.get();
    return 0;
}
