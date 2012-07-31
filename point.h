#include <iostream>
using namespace std;

class Point {
    public:
        Point() {
            x = 0;
            y = 0;
        }
        Point(const Point& p) {
            x = p.x;
            y = p.y;
        }
        Point(double xx, double yy) {
            x = xx;
            y = yy;
        }
        void read(istream& in) {
            in >> x >> y;
        }
        void print(ostream& out) {
            out << "(" << x << "," << y << ")" << endl;
        }
        bool operator<(const Point p) const {
            return x < p.x || (x == p.x && y < p.y);
        }
        bool operator==(const Point& p) const {
            return x == p.x && y == p.y;
        }
        double x, y;
};
