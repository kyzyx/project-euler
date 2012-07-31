/*----------------------------------------------------------------
 *  pe144.java
 *  Author:        Edward Zhang
 *  Written:       2011-06-18
 *  Last updated:  2011-06-18
 *
 *  Compilation:   javac pe144.java
 *  Execution:     java pe144
 *  Dependencies:  
 *
 *  % java pe144
 *----------------------------------------------------------------*/

public class pe144_visualizer {
    private static class Pt {
        public double x;
        public double y;
        public Pt(double xx, double yy) {
            x = xx; y = yy;
        }
        public Pt(Pt p) {
            x = p.x; y = p.y;
        }
        public Pt() {
            x = 0; y = 0;
        }
        
        public void set(double xx, double yy) {
            x = xx; y = yy;
        }
        public void set(Pt p) {
            x = p.x; y = p.y;
        }
    }
    
    public static double distancel(Pt a, Pt b) {
        return (a.x - b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
    }
    
    public static void dl(Pt a, Pt b) {
        StdDraw.line(a.x, a.y, b.x, b.y);
    }
    public static void main(String[] args) {
        StdDraw.setXscale(-12, 12);
        StdDraw.setYscale(-12, 12);
        StdDraw.clear(java.awt.Color.WHITE);
        StdDraw.setPenColor(java.awt.Color.BLACK);
        
        StdDraw.ellipse(0.,0.,5,10);
        StdDraw.setPenColor(java.awt.Color.RED);
        
        long bounces = 1;
        Pt curr = new Pt(1.4, -9.6);
        Pt prev = new Pt(0, 10.1);
        dl(curr, prev);
        
        Pt n = new Pt();
        Pt tmp = new Pt();
        Pt point1 = new Pt();
        Pt point2 = new Pt();
        while(true) {
            tmp.set(curr);
            double nscale = Math.sqrt(curr.x*curr.x*16 + curr.y*curr.y);
            n.set(4*curr.x/nscale, curr.y/nscale);
            StdDraw.setPenColor(java.awt.Color.GREEN);
            StdDraw.line(tmp.x+n.x, tmp.y+n.y, tmp.x-n.x, tmp.y-n.y);
            double dot = (prev.x-curr.x)*n.x + (prev.y-curr.y)*n.y;
            curr.set(2*curr.x - prev.x + 2*dot*n.x, 
                     2*curr.y - prev.y + 2*dot*n.y);
        
            StdDraw.setPenColor(java.awt.Color.BLUE);
            dl(tmp, curr);
            StdDraw.show(1000);
            double A = -(curr.y - tmp.y);
            double B = curr.x - tmp.x;
            double C = A*curr.x + B*curr.y;
            double A2 = A*A;
            double B2 = B*B;
            double C2 = C*C;
            
//            if (A2 > B2) {
//                /*x = C/A - B/Ay;
//                 x^2 = (C^2 - 2BCy + B^2y^2)/A^2
//                 
//                 so we have 
//                 (4*B2 + A2)*y^2 - 8BCy + 4C2 - 100A2 = 0*/
//                StdDraw.setPenColor(java.awt.Color.ORANGE);
//                double y1 = (4*B*C + Math.sqrt(16*B2*C2 - (4*B2 + A2)*(4*C2 - 100*A2)))/(4*A2+B2);
//                double y2 = (4*B*C - Math.sqrt(16*B2*C2 - (4*B2 + A2)*(4*C2 - 100*A2)))/(4*A2+B2);
//                
//                double x1 = C/A - B*y1/A;
//                double x2 = C/A - B*y2/A;
//                point1.set(x1, y1);
//                point2.set(x2, y2);
//            }
//            else {
                StdDraw.setPenColor(java.awt.Color.RED);
                double x1 = (A*C + Math.sqrt(A2*C2 - (4*B2 + A2)*(C2 - 100*B2)))/(4*B2+A2);
                double x2 = (A*C - Math.sqrt(A2*C2 - (4*B2 + A2)*(C2 - 100*B2)))/(4*B2+A2);
                
                double y1 = C/B - A*x1/B;
                double y2 = C/B - A*x2/B;
                point1.set(x1, y1);
                point2.set(x2, y2);
//            }
            double d1 = distancel(point1, tmp);
            double d2 = distancel(point2, tmp);
            
            if (d1 > d2) {
                curr.set(point1);
            }
            else {
                curr.set(point2);
            }
            
            prev.set(tmp);
            if ((curr.x < 0.01 && curr.x > -0.01) && curr.y > 9) break;
            
            
            dl(curr, prev);
            ++bounces;
            StdDraw.show(1000);
        }
        System.out.println(bounces);
    }
}
