#include <iostream>

using namespace std;

int a[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};
int teens[] = {3, 6, 6, 8, 7, 7, 7, 9, 9, 8};
int ties[] = {6, 6, 5, 5, 5, 7, 6, 6};

int main() {
    int hundred = 7;
    
    int t1 = 0; // Sum of single digits
    int t2 = 0;
    for(int i = 0; i < 10; ++i) {
        t1 += a[i];
    }
    
    for(int i = 0; i < 8; ++i) {
        t2 += ties[i]; 
    }
    t2 *= 10;   //tens digit 
    
    t2 += t1*9; // Don't count 10-19
    for(int i = 0; i < 10;++i) {
        t2 += teens[i];
    }
    // t2 now has sum from 1 to 99
    t2 *= 10;
    
    
    t2 += hundred*900; // "hundred"
    t2 += 3*(900-9);   // "and"
    t2 += t1*100;      // n hundred
    
    cout << t2 + 3 + 8 << endl; // "one thousand"
    cin.get();
    return 0;
}
