public class pe235 {
    public static double u(double r, int k){
        return (900 - 3*k)*Math.pow(r, k-1);
    }
    public static double f(double r) {
        double ret = 0;
        for(int i=1; i<5001; i++) ret += u(r, i);
        return ret + 6e11;
    }
    
    public static void main(String[] args) {
        //Experimentally derive upper and lower limits of 1 and 1.01
        double upper = 1;
        double lower = 1.01;
        double mid;
        for(int i=0; i<100; i++) {
            mid = (upper + lower)/2;
            if(f(mid) > 0) upper = mid;
            else lower = mid;
            System.out.println(mid);
        }
    }
}