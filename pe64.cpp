#include <iostream>
#define fori(n) for(int i=0; i<n; i++)
#define N 10000

using namespace std;

int sqrt[100001];

class term{
    public: int a;  //Term
            int n;  //Root
            int num, den; //(sqrt(n) - num)/ den
            
            term(){
                a = 1; 
                n = 1;
                num = 1;
                den = 1;
            }
            term(int aa, int nn, int xx, int yy){
                a = aa;
                n = nn;
                num = xx;
                den = yy;
            }
            
            void set(int aa, int nn, int xx, int yy){
                a = aa;
                n = nn;
                num = xx;
                den = yy;
            }
            term next(){
                term* ret;                
                int newDen = ((n-num*num)/den);
                int newTerm = (sqrt[n]+num)/newDen;
                ret = new term(newTerm, n, -(num-newDen*newTerm), newDen);
                return *ret;
            }
            
            term& operator=(const term &b){
                if(this == &b) return *this;
                a = b.a;
                n = b.n;
                num = b.num;
                den = b.den;
                return *this;
            }
            bool operator==(const term& b){
                if(a == b.a && n == b.n && num == b.num && den == b.den) return true;
                else return false;
            }
            
            void dump(){
                cout << a << " + (sqrt(" << n << ") - " << num << ")/" << den << endl;
            }
};

int period(int n){
    term t[1000];
    t[0].set(sqrt[n],n,sqrt[n],1);
    bool loop = false;
    int z=0;
    while(!loop){
        t[z+1] = t[z].next();
        //t[z].dump();
        ++z;
        fori(z){
            if(t[z] == t[i]){
                return z-i;
            }
        }
    }
}

int main(){
    //Init
    fori(100){
        sqrt[i*i] = 0;
        for(int j=i*i+1; j<(i+1)*(i+1); j++){
            sqrt[j] = i;
        }
    }
    int tot = 0;
    fori(N+1){
        if(sqrt[i] == 0) continue;
        //else cout << i << ":" << period(i) << endl;
        if(period(i)%2) tot++;
    }
    cout << tot << endl;
    
    cin.get();
    return 0;
}
