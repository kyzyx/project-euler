#include <iostream>

using namespace std;

/*
 aaaa
 bbbx
 cxx-
 x---
*/

int main() {
    int total = 0;
    int s, a1, a2, a3, a4, b1, b2, b3, b4, c1, c2, c3, c4, d1, d2, d3, d4;
    for(a1 = 0; a1 < 10; ++a1) {
    for(a2 = 0; a2 < 10; ++a2) {
    for(a3 = 0; a3 < 10; ++a3) {
    for(a4 = 0; a4 < 10; ++a4) {
    for(b2 = 0; b2 < 10; ++b2) {
    if (b2 > a2 + a3 + a4 || b2 > a1 + a3 + a4) break;
    for(b3 = 0; b3 < 10; ++b3) {
    if (b3 > a1 + a2 + a4 || b3 > a1 + a2 + a3) break;
    for(b1 = 0; b1 < 10; ++b1) {
    if (b1 > a2 + a3 + a4 || b1 + b2 + b3 > a1 + a2 + a3 + a4) break;
    for(c1 = 0; c1 < 10; ++c1) {
        s = a1 + a2 + a3 + a4;
        b4 = s - b1 - b2 - b3;
        d1 = s - c1 - b1 - a1;
        c2 = s - d1 - b3 - a4;
        c3 = s - b2 - b3 - c2;
        c4 = s - c1 - c2 - c3;
        d2 = s - a2 - b2 - c2;
        d3 = s - a3 - b3 - c3;
        d4 = s - a4 - b4 - c4;
        if (b4 < 0 || b4 > 9 || c2 < 0 || c2 > 9 || c3 < 0 || c3 > 9) continue;
        if (c4 < 0 || c4 > 9 || d1 < 0 || d1 > 9 || d2 < 0 || d2 > 9) continue;
        if (d3 < 0 || d3 > 9 || d4 < 0 || d4 > 9) continue;
        
        if (d1 + d2 + d3 + d4 != s) continue;
        if (a1 + b2 + c3 + d4 != s) continue;
        ++total;
    }}}}}}}}
    cout << total << endl;
    cin.get();
    return 0;
}
