#include <iostream>
#include <deque>
#define MAX 20000
#define NM 12001

using namespace std;

struct el{
    int n;
    int sum;
};

typedef deque<el> ellist;

bool isprime[MAX];
int primes[10000];
int np = 0;

el& newEl(int nn, int ss){
    el* ret;
    ret = new el;
    ret->n = nn;
    ret->sum = ss;
    return *ret;
}

void init(){
    for(int i=0; i<MAX; i++) isprime[i] = true;
    for(int i=2; i<MAX; i++){
        if(isprime[i]){
            for(int j = i*2; j<MAX; j+= i){
                isprime[j] = false;
            }
            primes[np++] = i;
        }
    }
}

ellist prodsum[MAX];
int minprodsum[NM];

int main(){
    init();
    for(int i=0; i<NM; i++) minprodsum[i] = 999999;
    for(int i=2; i<MAX; i++){
        prodsum[i].push_back(newEl(1,i));
        //cout << i << ":1," << i << " ";
        for(int j=2; j <= i>>1; j++){
            if(i%j==0){
                for(int k=0; k<prodsum[i/j].size(); k++){
                    //cout << prodsum[i/j][k].n+1 << "," << prodsum[i/j][k].sum+j << " ";
                    prodsum[i].push_back(newEl(prodsum[i/j][k].n+1,prodsum[i/j][k].sum+j));
                }
            }
        }
        //cout << endl;
    }
    
    cout << "Done preprocessing" << endl;
    for(int i=2; i<MAX; i++){
        for(int j=0; j<prodsum[i].size(); j++){
            int n = prodsum[i][j].n + i - prodsum[i][j].sum;
            if(n<NM && n > 0 && i < minprodsum[n]) minprodsum[n] = i;
        }
    }
    cout << "Done min calcs" << endl;
    int nums[12000];
    nums[0] = 1;
    int j, nn = 0;
    //cout << "1:1" << endl;
    for(int i=2; i<13; i++){
        //cout << i << ":" << minprodsum[i] << endl;
        if(minprodsum[i] == 999999) cout << "!" << i << endl;
        for(j=0; j<nn; j++){
            if(nums[j] == minprodsum[i]) break;
        }
        if(j == nn) nums[nn++] = minprodsum[i];
    }
    int sum = 0;
    for(int i=0; i<nn; i++){
        sum += nums[i];
    }
    
    cout << "Sum is  " << sum << endl;
    cin.get();
    return 0;
}
