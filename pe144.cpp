#include <iostream>
#include <cmath>
#define PDD pair<double,double>

using namespace std;

double distancel(PDD a, PDD b) {
    return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}

int main() {
    unsigned long long bounces = 1;
    PDD curr = make_pair(1.4, -9.6);
    PDD prev = make_pair(0, 10.1);
    while(true){
        PDD tmp = curr;
        
        // Reflect
        double nscale = sqrt(curr.first*curr.first*16 + curr.second*curr.second);
        PDD n = make_pair(4*curr.first/nscale, curr.second/nscale);
        double dot = (prev.first-curr.first)*n.first + (prev.second-curr.second)*n.second;
        curr.first = 2*curr.first - prev.first + 2*dot*n.first;
        curr.second = 2*curr.second - prev.second + 2*dot*n.second;
        
        //cout << curr.first << "," << curr.second << "         ";
        
        // Intersect: (x,y) = (curr.first - tmp.first, curr.second - tmp.second)*t + (curr.first, curr.second)        
        double A = -(curr.second - tmp.second);
        double B = curr.first - tmp.first;
        double C = A*curr.first + B*curr.second;
        double A2 = A*A;
        double B2 = B*B;
        double C2 = C*C;
        
        PDD point1, point2;
        
        /*if (A2 > B2) {
            x = C/A - B/Ay;
            x^2 = (C^2 - 2BCy + B^2y^2)/A^2
            
            so we have 
            (4*B2 + A2)*x^2 - 8BCy + 4C2 - 100A2 = 0
            
            double y1 = (4*B*C + sqrt(16*B2*C2 - (4*B2 + A2)*(4*C2 - 100*A2)))/(4*A2+B2);
            double y2 = (4*B*C - sqrt(16*B2*C2 - (4*B2 + A2)*(4*C2 - 100*A2)))/(4*A2+B2);
            
            double x1 = C/A - B*y1/A;
            double x2 = C/A - B*y2/A;
            point1 = make_pair(x1, y1);
            point2 = make_pair(x2, y2);
        }
        else {
            /*y = C/B - A/Bx;
            y^2 = (C^2 - 2ACx + A^2x^2)/B^2
            so we have
            (4B^2 + A^2)x^2 - 2ACx + C^2 - 100B^2 = 0*/
            
            double x1 = (A*C + sqrt(A2*C2 - (4*B2 + A2)*(C2 - 100*B2)))/(4*B2+A2);
            double x2 = (A*C - sqrt(A2*C2 - (4*B2 + A2)*(C2 - 100*B2)))/(4*B2+A2);
            
            double y1 = C/B - A*x1/B;
            double y2 = C/B - A*x2/B;
            point1 = make_pair(x1, y1);
            point2 = make_pair(x2, y2);
        //}
        
        double d1 = distancel(point1, tmp);
        double d2 = distancel(point2, tmp);
        //cout << point1.first << "," << point1.second << " or " << point2.first << "," << point2.second << endl;
        if (d1 > d2) {
            curr = point1;
        }
        else {
            curr = point2;
        }
        
        prev = tmp;
        //cout << curr.first << "," << curr.second << " -- " << prev.first << "," << prev.second << endl;
        //cin.get();
        if ((curr.first < 0.01 && curr.first > -0.01) && curr.second > 9) break;
        bounces++;
        if (bounces % 1000000 == 0) cout << bounces << endl;
    }
    cout << bounces << endl;
    cin.get();
    return 0;
}
