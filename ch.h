#include <vector>
#include <algorithm>
#include "point.h"

using namespace std;

typedef vector<Point>::iterator vit;

// Simple ccw for points in general position
bool ccw2(const Point& p1, const Point& p2, const Point& p3) {
    return (p2.x - p1.x)*(p3.y - p1.y) > (p2.y - p1.y)*(p3.x - p1.x);
}

// From http://www.mathcs.duq.edu/simon/Fall05/cs300notes3.html for completeness
int ccw(const Point& p0, const Point& p1, const Point& p2) {
      int dx1=(p1.x-p0.x), dy1=(p1.y-p0.y);
      int dx2=(p2.x-p0.x), dy2=(p2.y-p0.y);
      if (dy1*dx2 < dy2*dx1) return 1;
      if (dy1*dx2 > dy2*dx1) return -1;
      if (dx1*dx2 < 0 || dy1*dy2 < 0) return -1;
      if (dx1*dx1 + dy1*dy1 >= dx2*dx2 + dy2*dy2)
          return 0;
      else
          return 1;
}

bool intersect(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    return ccw(p1, p2, p3) != ccw(p1, p2, p4) && ccw(p3, p4, p1) != ccw(p3, p4, p2);
}

Point intersection(const Point& p1, const Point& p2,
                   const Point& p3, const Point& p4) {
    // Determine line equations
    // |A1 B1| |x|   |C1|
    // |A2 B2| |y| = |C2|
    double A1, B1, C1, A2, B2, C2;
    A1 = p1.y - p2.y;
    B1 = p2.x - p1.x;
    C1 = A1*p1.x + B1*p1.y;
    A2 = p3.y - p4.y;
    B2 = p4.x - p3.x;
    C2 = A2*p3.x + B2*p3.y;
    // Solve for intersection

    // Parallel case: We are given points in G.P. so we don't worry about
    // collinear points, i.e. overlapping lines
    // We also assume that the lines do intersect at a single point.
    if (A1*B2 == B1*A2) {
        cerr << "Error: Parallel lines" << endl;
        return Point();
    }

    // Inverse of matrix:
    // | B2 -B1|
    // |-A2  A1|/D
    double D = A1*B2 - B1*A2;
    double x = (B2*C1 - B1*C2)/D;
    double y = (A1*C2 - A2*C1)/D;
    return Point(x,y);
}

void sortedch(vector<Point>& pts, vector<Point>& v) {
    int k = 0;
    v.resize(2*pts.size());
    // Lower hull
    for (int i = 0; i < pts.size(); ++i) {
        while (k >= 2 && !ccw(v[k-2], v[k-1], pts[i])) --k;
        v[k++] = pts[i];
    }
    // Upper hull
    int t = k+1;
    for (int i = pts.size()-2; i >= 0; --i) {
        while (k >= t && !ccw(v[k-2], v[k-1], pts[i])) --k;
        v[k++] = pts[i];
    }
    v.resize(k-1);
    reverse(v.begin(), v.end());
}
