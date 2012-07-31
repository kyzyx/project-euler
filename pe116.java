import java.math.*;

public class blockdistr{
   
    public static void main(String args[]){
       int m =50;
       BigInteger n;
       BigInteger numways[] = new BigInteger[10000];
       for(int i=0; i<m; i++){
           numways[i] = BigInteger.valueOf(1);
       }
       numways[m] = BigInteger.valueOf(2);
       BigInteger curr;
       for(int i=m+1; true; i++){
           curr = BigInteger.valueOf(1); // 1 for blank
           for(int bsize=m; bsize<=i; bsize++){
               for(int right = bsize-1; right<i; right++){
                   if(i-right-2 < m) curr = curr.add(numways[0]);    
                   else{
                       curr = curr.add(numways[i-right-2]);
                   }
               }
           }
           numways[i] = curr;
           System.out.println(i + ":" + curr);
           if(curr.compareTo(BigInteger.valueOf(1000000)) == 1) break;
       }

    }
}