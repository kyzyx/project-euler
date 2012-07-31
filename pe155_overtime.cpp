/* 3:40*/
#include <iostream>
#include <set>
#define MAX 19

using namespace std;

class frac {
    public:
        unsigned long long num;
        unsigned long long den;
        
        frac() {
            num = 0; den = 1;
        }
        frac(unsigned long long a, unsigned long long b, bool red=true) {
            num = a; den = b;
            if (red) reduce();
        }
        
        void reduce() {
            unsigned long long g = gcd(num, den);
            num /= g;
            den /= g;
        }
        
        static unsigned long long gcd(unsigned long long a, unsigned long long b) {
            if (b > a) return gcd(b, a);
            while(b > 0) {
                unsigned long long tmp = a;
                a = b;
                b = tmp%b;
            }
            return a;
        }
        
        static unsigned long long lcm(unsigned long long a, unsigned long long b) {
            return a / gcd(a, b) * b;
        }
        
        frac reciprocal() const{
            return frac(den, num, false);
        }
        frac operator+(const frac& b) const{
            unsigned long long l = lcm(den, b.den);
            return frac(num*(l/den) + b.num*(l/b.den), l);
        }
        frac operator*(const frac& b) const{
            unsigned long long g1 = gcd(num, b.den);
            unsigned long long g2 = gcd(den, b.num);
            return frac((num/g1) * (b.num/g2), (den/g2) * (b.den/g1), false);    
        }
        frac operator/(const frac& b) const{
            unsigned long long g1 = gcd(num, b.num);
            unsigned long long g2 = gcd(den, b.den);
            return frac((num/g1) * (b.den/g2), (den/g2) * (b.num/g1), false);
        }
        
        bool operator==(const frac& b) const{
            return num == b.num && den == b.den;
        }

        void print() {
            cout << num << "/" << den;
        }
};

struct cc {
    bool operator()(const frac& a, const frac& b) {
        frac tmp = a/b;
        return tmp.num < tmp.den;
    }
};

set<frac,cc> values[MAX];
set<frac,cc> allvals;

int main(){
    allvals.insert(frac(1,1));
    values[1].insert(frac(1,1));
    for(int i=2; i<MAX; i++){
        for(int j=1; j<=i/2; j++){
            for (set<frac>::iterator it = values[j].begin(); it != values[j].end(); ++it) {
                for(set<frac>::iterator jt = values[i-j].begin(); jt != values[i-j].end(); ++jt) {
                    frac a = (*it)+(*jt);
                    frac b = (*it)*(*jt)/a;
                    if (allvals.find(a) == allvals.end()) {
                        values[i].insert(a);
                        allvals.insert(a);
                    }
                    if (allvals.find(b) == allvals.end()) {
                        values[i].insert(b);
                        allvals.insert(b);
                    }
                }
            }
        }
        cout << i << ": " << values[i].size() << endl;
    }

    cout << allvals.size() << endl;
    cin.get();
    return 0;
}
