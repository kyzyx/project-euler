import java.math.*;
import java.io.*;

class pe13 {
    public static void main(String[] args) {
        BufferedReader in;
        try{
             in = new BufferedReader(new FileReader("Inputs/n50100.txt"));
             BigInteger tot = BigInteger.ZERO;
             for(int i = 0; i < 100; ++i) {
                 BigInteger n = new BigInteger(in.readLine());
                 tot = tot.add(n);
             }
             System.out.println(tot.toString().substring(0,10));
        } catch(Exception e) {
            System.err.println("Input file not found!");
        }        
    }
}