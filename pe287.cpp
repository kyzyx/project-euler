#include <iostream>
#define M 24

using namespace std;

const long long MM = 1<<(M-1);

enum {
    BLACK,
    WHITE
};

int bw(long long x, long long y) {
    if ((x-MM)*(x-MM) + (y-MM)*(y-MM) > MM*MM) return WHITE;
    return BLACK;
}

long long slen(int x, int y, int dim, int q) {
    if (q == 0) {  // lower left
        if (bw(x,y) == BLACK) return 2;
        if (bw(x+dim-1,y+dim-1) == WHITE) return 2;
    } else if (q == 1) {   // lower right
        if (bw(x,y+dim-1) == WHITE) return 2;
        if (bw(x+dim-1,y) == BLACK) return 2;
    } else if (q == 2) {   // upper left
        if (bw(x,y+dim-1) == BLACK) return 2;
        if (bw(x+dim-1,y) == WHITE) return 2;
    } else {  // upper right
        if (bw(x,y) == WHITE) return 2;
        if (bw(x+dim-1,y+dim-1) == BLACK) return 2;
    }
    return 1 + slen(x,y,dim/2,q) + slen(x,y+dim/2,dim/2,q) + slen(x+dim/2,y,dim/2,q) + slen(x+dim/2,y+dim/2,dim/2,q);
}

int main() {
    long long s1 = slen(0,0,MM,0);
    cout << s1 << endl;
    long long s2 = slen(MM,0,MM,1);
    cout << s2 << endl;
    long long s3 = slen(MM,MM,MM,3);
    cout << s3 << endl;
    cout << 1 + s1 + 2*s2 + s3 << endl;
    return 0;
}
