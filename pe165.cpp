#include <iostream>
#include <set>
#define N 5000
#include "ch.h"

using namespace std;

Point p1[N];
Point p2[N];

set<Point> intersections;

int main() {
    unsigned long long n = 290797;
    n = (n*n)%50515093;
    int a, b;
    for (int i = 0; i < N; ++i) {
        a = n%500;
        n = (n*n)%50515093;
        b = n%500;
        n = (n*n)%50515093;
        p1[i] = Point(a,b);
        a = n%500;
        n = (n*n)%50515093;
        b = n%500;
        n = (n*n)%50515093;
        p2[i] = Point(a,b);
    }
    p1[0].print(cout);
    p2[0].print(cout);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (intersect(p1[i], p2[i], p1[j], p2[j])) {
                Point p = intersection(p1[i], p2[i], p1[j], p2[j]);
                if (p == p1[i] || p == p2[i] || p == p1[j] || p == p2[j])
                    continue;
                if (p) intersections.insert(p);
            }
        }
    }

    cout << intersections.size() << endl;
    return 0;
}
