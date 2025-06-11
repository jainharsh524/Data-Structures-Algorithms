package Math;

//Asked in amazon
public class findNThMagicNumber {
    public static int magicNumber(int n){
        int sum = 0;
        int count = 1;
        while(n>=1){
            int dig = n&1;
            sum = (int) (sum+dig*Math.pow(5,count));
            n = n>>1;
            count++;
        }
        return sum;
    }
    public static void main(String[] args) {
        System.out.println(magicNumber(1));
    }
}
