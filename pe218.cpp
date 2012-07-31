#include <iostream>
#define MAX 10000

using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    long long tmp;
    if (b>a) {
        tmp = a;
        a = b;
        b = a;
    }
    while (b > 0) {
        tmp = a;
        a = b;
        b = tmp%b;
    }
    return a;
}
/* a^2 + b^2 = c^2, c <= 10^16, c = c'^2
   c'^2 = p^2 + q^2 for rel-prime p, q
   c' = i^2 + j^2 for rel-prime i, j
   p = 2*i*j, q = i*i-j*j
   a = p*p - q*q = 6i2j2 - i4 - j4), b = 2*p*q = 4ij
   Area = 2ij(6i2j2 - i4 - j4)(i+j)(i-j) => divisible by 4
   Case 1: i = 2 (mod 3) 
       j = 1 mod 3, so i+j = 0 mod 3 => is divisible by 3
   Case 2: i = 0 (mod 3) 
        Is divisible by 3
    Try 7
   
*/
int main() {
    /*unsigned long long p, q, a, b;
    long long tot = 0;
    for(unsigned long long i = 1; i < MAX; i+=2) {
        for(unsigned long long j = 2; j < MAX; j+=2) {
            if (gcd(i,j) == 1) {
                
                p = 2*i*j;
                if (i > j) q = i*i - j*j;
                else q = j*j - i*i;
                if (q%2 == 0 || gcd(p,q) != 1) continue;
                b = p*q;
                if (p > q) a = p*p - q*q;
                else a = q*q - p*p;
                //cout << a << "+" << b << "=" << p*p + q*q << endl;
                if ((a%7)*(b%7)*(a%3)*(b%3)*(a%2)*(b%2)) {
                    ++tot;
                }
            }   
        }
    }
    cout << tot << endl;*/
    
    // Try all i, j mod 7
    for(int i = 1; i < 7; i++) {
        for(int j = 1; j < 7; j++) {
            if ((i+j) % 7 == 0) continue;
            if ((i-j) % 7 == 0) continue;
            if ((6*i*i*j*j - i*i*i*i - j*j*j*j) % 7 == 0) continue;
            cout << i << ", " <<  j << endl;
        }
    }
    // Well, I did this after the stupid way gave 0, but we'd normally check how many
    // relatively prime i,j, existed for the total. 
    cin.get();
    return 0;
}
