import java.math.*;

public class blockdistr117{
   
    public static void main(String args[]){
       int m = 50;
       BigInteger n;
       BigInteger numways[][] = new BigInteger[5][];
       for(int i=0; i<5; i++){
           numways[i] = new BigInteger[1000];
           for(int j=0; j<i; j++){
               numways[i][j] = BigInteger.valueOf(0);
           }
           numways[i][i] = BigInteger.valueOf(1);
       }
       
       BigInteger curr;
       for(int i=3; i<m+1; i++){
           for(int bsize=2; bsize<5; bsize++){
               curr = BigInteger.valueOf(0);
               for(int right = bsize-1; right<i; right++){
                   if(i-right-1 < bsize) curr = curr.add(numways[bsize][bsize]);    
                   else{
                       curr = curr.add(numways[bsize][i-right-1]).add(BigInteger.valueOf(1));
                   }
                  // if(i==5 && bsize == 2) System.out.println(curr);
               }
              numways[bsize][i] = curr;
           }
           BigInteger tmp = numways[2][i].add(numways[3][i]).add(numways[4][i]);
           System.out.println(i + ":" + numways[2][i] + " " + numways[3][i] + " " + numways[4][i] + " " + tmp);
       }

    }
}