import java.math.*;

public class blockdistr116{
   
    public static void main(String args[]){
       int m = 50;
       BigInteger n;
       BigInteger numways[] = new BigInteger[10000];
       for(int i=0; i<2; i++){
           numways[i] = BigInteger.valueOf(1);
       }
       numways[2] = BigInteger.valueOf(2);
       BigInteger curr;
       for(int i=3; i<m+1; i++){
           curr = BigInteger.valueOf(1); // 1 for blank
           for(int bsize=2; bsize<=4; bsize++){
               for(int right = bsize-1; right<i; right++){
                   if(i-right-1 < 1) curr = curr.add(numways[0]);    
                   else{
                       curr = curr.add(numways[i-right-1]);
                   }
               }
              // if(i==5) System.out.println(curr);
           }
           numways[i] = curr;
           System.out.println(i + ":" + curr);
       }

    }
}