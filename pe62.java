import java.math.*;

public class pe62{ 
    public static int isperm(BigInteger a, BigInteger b){
        int counts[] = new int[10];
        for(int i=0; i<10; i++) counts[i] = 0;
        String s = a.toString();
        String t = b.toString();
        if(s.length() != t.length()) return -1;
        for(int i=0; i<s.length(); i++){
            ++counts[s.charAt(i)-'0'];
            --counts[t.charAt(i)-'0'];
        }
        for(int i=0; i<10; i++) if(counts[i] != 0) return 0;
        return 1;
    }
    
    public static void findPerms(BigInteger b, int n, int min){
        int count = 1;
        int tmp;
        for(int i=min+1; i<10000; i++){    
            tmp = isperm(b, BigInteger.valueOf(i*i).multiply(BigInteger.valueOf(i)));
            if(tmp == -1 ) return;
            else if(tmp == 1){
                count++;
                if(count == n) {
                    System.out.println(b);
                    return;
                }
            }
        }
    }
    
    public static void main(String args[]){
        for(int i=300; i<10000; i++){
             findPerms(BigInteger.valueOf(i*i).multiply(BigInteger.valueOf(i)), 5, i);
             if(i%1000
        }
    }
}
