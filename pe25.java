import java.math.*;

public class pe25 {
    public static void main(String[] args) {
        BigInteger f1 = BigInteger.ONE;
        BigInteger f2 = BigInteger.ONE;
        for(int i = 3; true; ++i) {
            BigInteger tmp = f1;
            f1 = f2;
            f2 = tmp.add(f1);
            
            if (f2.toString().length() >= 1000) {
                System.out.println(i);
                break;
            }
        }
    }
}