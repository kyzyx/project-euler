/*----------------------------------------------------------------
 *  Art.java
 *  Author:        Edward Zhang
 *  Written:       10/8/2009
 *  Last updated:  10/12/2009
 *  netID:         edwardz
 *  Precept:       B03
 *
 *  Compilation:   javac Art.java
 *  Execution:     java Art n
 *
 *  This program draws the Dragon Curve to a depth of n iterations
 *  The program includes changing colours which show the curve's self-
 *  similarity and tiling properties even within the larger sections.
 *  For interesting renderings use a depth between 9 and 17.
 *
 *  Note on time: (2.53 GHz processor, one or two other programs running)
 *  For any depth under 6, the program is essentially instantaneous
 *  For a depth of 11, the rendering takes about 5 seconds
 *  For a depth of 16, the rendering takes 2-3 minutes
 *  For a depth of 17, the rendering takes about 5 minutes
 *  For any depth > 17, the level of detail gained is marginal
 *  and the running time is too great.
 *  In general, increasing n by one should double the running time
 *  because each call to dragon() calls dragon() twice.
 *
 *  % java Art 9
 *         [Opens new window displaying Dragon curve of depth 9]
 *
 *----------------------------------------------------------------*/

 public class dragon {
     //  Constants - small difference to keep floating
     //  point arithmetic accurate
     private static final double EPSILON = 1e-15;
    private static long ns = 0;
    private static long end = 1000000000000L;
    private static long x = 0;
    private static long y = 0;
     //  Color variables
     //  Red, green, and blue of current color
     private static int tmp = 1;
     private static int count = 0;     //  # lines drawm since last color change

     //  Parameters set based on input
     private static int depth = 0;     //  Depth at which to draw the curve
     private static double scale = 1;  //  Change color after scale lines
                                      //  Default value makes depth < 9 curves
                                      //  still interesting


     //  dragon() takes the depth n and two endpoints of a line segment; it
     //  recursively calls itself by replacing the line segment with two
     //  orthogonal line segments that, with the original line, forms a
     //  45-45-90 triangle.
     public static void dragon(int n, double x1, double y1,
                                      double x2, double y2) {
         if (n == 0) {        //  Base Case
             //changeColor();                 //  Update colors
             //StdDraw.line(x1, y1, x2, y2);  //  Draw line
             if(ns == end){
                 System.out.println(x*64 + "," + y*64);
                System.exit(0);
            }
             else{
                 if(x1 == x2){
                    if(y2 < y1) y--;
                    else y++;
                 }
                 else{
                    if(x2 < x1) x--;
                    else x++;
                 }
                 ns++;
             }
             return;                        //  Exit
         }

         //  Recursive calls
         double s;                 //  Used to calculate "height" of triangle
         if (Math.abs(x2 - x1) <= EPSILON) {      //  If the line is vertical
             s = (y2 - y1)/2;                    //  Triangle height = base/2
             //  Keeping orientation the same & alternating motif facing,
             if ((depth - n)/2 % 2 == 0) {
                  //  Don't draw this line, but replace it with the two lines
                  //  that make the motif - similar meanings for subsequent
                  //  cases.
                  dragon(n - 1, x1, y1, x1 + s, (y1 + y2)/2);
                  dragon(n - 1, x1 + s, (y1 + y2)/2, x2, y2);
              }
              else {
                  dragon(n - 1, x1, y1, x1 - s, (y1 + y2)/2);
                  dragon(n - 1, x1 - s, (y1 + y2)/2, x2, y2);
              }
          }
          else if (Math.abs(y2 - y1) <= EPSILON) {   //  If line is horizontal
             s = (x2 - x1)/2;
             if ((depth - n)/2 % 2 == 0) {
                  dragon(n - 1, x1, y1, (x1 + x2)/2, y1 + s);
                  dragon(n - 1, (x1 + x2)/2, y1 + s, x2, y2);

              }
              else {
                 dragon(n - 1, x1, y1, (x1 + x2)/2, y1 - s);
                 dragon(n - 1, (x1 + x2)/2, y1 - s, x2, y2);
              }
          }
          else {                                    //  If line is diagonal
              if ((depth - n)/2 % 2 == 0) {
                  dragon(n - 1, x1, y1, x1, y2);
                  dragon(n - 1, x1, y2, x2, y2);
              }
              else {
                  dragon(n - 1, x1, y1, x2, y1);
                  dragon(n - 1, x2, y1, x2, y2);
              }
          }
     }

     public static void main(String[] args) {
         //  Input
        depth = Integer.parseInt(args[0]);
        while(end %2 == 0){
            end /=2;
            depth--;
        }
        //  Draw the curve
        dragon(depth, -100000, 0, 100000, 0);
     }
 }