package Recursion;

public class levelOneRecursion {
    //1. n to 1
    public static void printTopToBottom(int n){
        System.out.print(n+" ");
        if(n==1) return;
        printTopToBottom(n-1);
    }
    //2. 1 to n
    public static void printBottomToTop(int n){
        if(n==0) return;
        printBottomToTop(n-1);
        System.out.print(n+" ");
    }
    //3. ProductTillN Till N
    public static int productTillN(int n){
        if(n==1) return n;
        else return n*productTillN(n-1);
    }
    //4. Sum of digits
    public static int sumOfDigits(int n){
        if(n==0) return n;
        else return n%10+sumOfDigits(n/10);
    }
    //5. Reverse a number
    static int sum;
    public static int reverseInteger(int n){
        if(n == 0) return n;
        else {
            int rem = n%10;
            sum = sum*10+ rem;
            reverseInteger(n/10);
        }
        return sum;
    }
    //6. CountZeroes
    public static int countZeroes(int n) {
        return helper(n, 0);
    }

    // special pattern, how to pass a value to above calls
    private static int helper(int n, int c) {
        if (n == 0) {
            return c;
        }
        int rem = n % 10;
        if (rem == 0) {
            return helper(n/10, c+1);
        }
        return helper(n/10, c);
    }
    public static void main(String[] args) {
        printTopToBottom(5);
        System.out.println();
        printBottomToTop(5);
        System.out.println();
        System.out.println(productTillN(5));
        System.out.println(sumOfDigits(594));
        System.out.println(reverseInteger(594));
    }
}
