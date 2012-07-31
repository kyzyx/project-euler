import java.math.*;

public class pe58{ 
    public static boolean isprime(long n){
        return BigInteger.valueOf(n).isProbablePrime(10);
    }
    public static void main(String args[]){
       long curr = 1;
       long numP = 0;
       for( long i=1; i<100000; i++){
           for(int j=0;j<4; j++){
               curr += 2*i;
               if(isprime(curr)) numP++;
           }
           if(i%200 == 0){            
               System.out.println(numP + "/" + (4*i+1));
           }
           if(10*numP < (4*i+1)){
               System.out.println(2*i+1); 
               System.out.println(numP + "/" + (4*i+1));
               break;
           }
           
       }
    }
}
