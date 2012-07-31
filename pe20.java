import java.math.*;

public class pe20 {
    public static long sd(BigInteger num){
            long n = 0;
            String s = num.toString();
            for(int i=0; i<s.length(); i++){
                n += s.charAt(i) - '0';
            }
            return n;
        }
    
    public static void main(String[] args) {
        BigInteger n = BigInteger.ONE;
        for(int i = 2; i < 101; ++i) {
            n = n.multiply(BigInteger.valueOf(i));
        }
        System.out.println(sd(n));
    }
}