#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#define fori(N) for(int i=0; i<N; i++)
#define forj(N) for(int j=0; j<N; j++)
#define fork(N) for(int k=0; k<N; k++)
//#define abs(a) a>0?a:-a

using namespace std;

bool isprime[9000001];
int primes[6000000];
unsigned long factorial[100];
long numprimes = 0;

unsigned long fignum(long s, long n){
    return 2*n+(s*n*(n-1))/2-n*n;
}
int pow(int n, int m){
    int r = 1;
    fori(m) r*=n;
    return r;
}
int log10(unsigned long n){
    int i;
    for(i=0;n>=1;i++){
        n/=10;
    }
    return i;
}

int numdigs(double n){
    int i;
    for(i=0;n>=1;i++){
        n/=10;
    }
    return i;
}
void initialize(){
    //primes
        string primefnames[10] = {"prime1m.txt"  , "prime1m2m.txt", "prime2m3m.txt", 
                                 "prime3m4m.txt", "prime4m5m.txt", "prime5m6m.txt", 
                                 "prime6m7m.txt", "prime7m8m.txt", "prime8m9m.txt", 
                                 "prime9m10m.txt"};
    fori(9000001) isprime[i] = false;
    ifstream* in;
    int c;
    fori(9){
        in = new ifstream;
        in->open(primefnames[i].c_str());
        in->seekg(0, ios::beg);
        while(!in->eof()){
            *in >> c;
            isprime[c] = true;
            primes[numprimes++] = c;
        }
        in->close();
    }
    
    factorial[0] = 1;
    for(unsigned long i=1; i<100; i++){
        factorial[i] = factorial[i-1]*i;
    }
}
/*
double ncr(int n, int k){
    
}*/
/*
long factorial(int n){
    long r = 1;
    for(int i=2; i<=n; i++) r*=i;
    return r;
}*/

// Triangular Number
long tri(int n){
    return ((n+1)*n)/2;
}

//Factors
int numfac(int n){
    int t = 0;
    int l = n/2;
    for(int i=1; i<=l; i++){
        if(n%i == 0) t++;
    }
    return t+1;
}

// Word value
int wordval(string s){
    int t = 0;
    fori(s.length()){
        t += s[i] - 'A' + 1;
    }
    return t;
}

// for each digit
unsigned long dodigit(unsigned long n){
    unsigned long t = 1;
    int d;
    while(n>0){
        d = n%10;
        if(d%2 == 0) return 0;
        //do something
        //t += factorial(d);
        //end
        n/=10;
    }
    return t;
}

bool isPerm(int m, int n){
    int d1[10];
    int d2[10];
    int numd = log10(m);
    if(numd != log10(n)) return false;
    int i;
    for(i=0; n>0; i++){
        d1[i] = n%10;
        d2[i] = m%10;
        n/=10; m/=10;
    }
    sort(d1,d1+numd);
    sort(d2, d2+numd);
    fori(numd) if(d1[i] != d2[i]) return false;
    return true;
}

bool isPal(unsigned long long n){
    int digs[20];
    int l10 = log10(n)+1;
    fori(l10/2){
        digs[i] = n%10; 
        n/=10;
    }    
    if(l10%2 == 1) n/=10;
    fori(l10/2){
        if(n%10 != digs[l10/2 - i - 1]) return false;
        n/=10;
    }
    return true;
}

bool isPal(string s){
    fori(s.length()/2){
        if(s[i] != s[s.length()-i-1]) return false;
    }
    return true;
}
bool isPD(int n){
    int d = numdigs(n); //if(numdigs(n) < d) return false;
    bool digitIn[10];
    for(int i=0; i<10; i++) digitIn[i] = false;
    for(int j=0; j<d; j++){
         digitIn[n%10] = true;       
         n /= 10; 
    }
    for(int i=1; i<d+1; i++) if(!digitIn[i]) return false;
    return true;
}
string boolstr(int n){
    if(n == 0) return "0";
    string s = "";
    int d ;
    while(n>0){
        d = n%2;
        s = (char)('0' + d) + s;
        n/=2;
    }
    return s;
}
