import java.math.*;

public class pe56 {
    public static final BigInteger ten = BigInteger.valueOf(10);
    public static int sd(BigInteger n) {
        
        int tot = 0;
        while(n.compareTo(BigInteger.ZERO) > 0) {
            tot += n.mod(ten).intValue();
            n = n.divide(ten);
        }
        return tot;
    }
    public static void main(String[] args) {
        int msd = 18;
        for(int i = 2; i < 100; ++i) {
            for(int j = 2; j < 100; ++j) {
                BigInteger n = BigInteger.valueOf(i).pow(j);
                int csd = sd(n);
                if (msd < csd) msd = csd;
            }
        }
        System.out.println(msd);
    }
}