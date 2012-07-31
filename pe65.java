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
        public long sumNum(){
            long n = 0;
            String s = num.toString();
            for(int i=0; i<s.length(); i++){
                n += s.charAt(i) - '0';
            }
            return n;
        }
        /*string toString(){
            return
        }*/
        public void print(){
            System.out.println(num + "/" + den);
        }

        public static void main(String args[]){
            int nc = 99;
            int coef[] = new int[nc+1];
            coef[0] =2;
            int z = 1;
            for(int i=1; i<nc+1; i++){
                if(i%3 == 2) coef[i] = z++*2;
                else coef[i] = 1;
            }
            frac res[] = new frac[nc+1];
            res[0] = new frac(1,coef[nc]);
            for(int i=1; i<nc; i++){
                // sqrt(2)
                //res[i] = res[i-1].addC(1).recip().addC(1);

                //e
                res[i] = res[i-1].addC(coef[nc-i]).recip();
                //res[i].print();
            }
            System.out.println(res[nc-1].addC(coef[0]).sumNum());
        }

};




