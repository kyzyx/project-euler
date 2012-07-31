import java.math.*;

class frac{
    private BigInteger num;
    private BigInteger den;

        public frac(){
            num = BigInteger.valueOf(0); den = BigInteger.valueOf(1);
        }
        public frac(int n, int d){
            num = BigInteger.valueOf(n);
            den = BigInteger.valueOf(d);
        }
        public frac(BigInteger n, BigInteger d){
            num = n;
            den = d;
        }
        public frac addC(int n){
            return new frac(num.add(den.multiply(BigInteger.valueOf(n))), den);
        }
        public frac recip(){
            return new frac(den, num);
        }
        public boolean moreDigits(){
            return (num.toString().length()>den.toString().length());
        }
        /*string toString(){
            return
        }*/
        public void print(){
            System.out.println(num + "/" + den);
        }

        public static void main(String args[]){
            frac t = new frac(3, 2);
            frac res[] = new frac[1001];
            res[1] = new frac(3,2);
            int num = 0;
            for(int i=2; i<1001; i++){
                res[i] = res[i-1].addC(1).recip().addC(1);
                //res[i].print();
                if(res[i].moreDigits()) num++;
            }
            System.out.println(num);
        }

};




