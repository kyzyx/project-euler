import java.math.*;

public class pe16 {
    public static long sd(BigInteger num){
            long n = 0;
            String s = num.toString();
            for(int i=0; i<s.length(); i++){
                n += s.charAt(i) - '0';
            }
            return n;
        }
    
    public static void main(String[] args) {
        BigInteger n = BigInteger.valueOf(2);
        for(int i = 2; i < 1001; ++i) {
            n = n.multiply(BigInteger.valueOf(2));
        }
        System.out.println(sd(n));
    }
}