#include <iostream>
#include <fstream>

#define fori(N) for(int i=0; i<N; i++)
#define max(a,b) a>b?a:b

using namespace std;

int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

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

unsigned long factSum(unsigned long n){
    unsigned long sum = 0;
    int d;
    while(n>0){
        d = n%10;
        sum += fact[d];
        n/=10;
    }
    return sum;
}

unsigned long lengthChain(int n){
    unsigned long chain[60];
    chain[0] = n;
    int z = 1;
    int j;
    unsigned long num = n;
    for(int j=0; j<60; j++){
        num = factSum(num);
        fori(z){
            if(chain[i] == num) return j+1;
        }
        chain[z++] = num;
    }
    return j; 
}

int main(){
    
    int n = 0;
    fori(1000000){
        if(lengthChain(i) == 60) n++;
    }
    cout << n;
    cin.get();
    return 0;
}   
