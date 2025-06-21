package Bitwise;

public class findNumbersOfDigitsInAnyBase {
    public static int noOfDigits(int n, int base){
        return (int) (Math.log(n)/Math.log(base)); //formula for finding the number of digits in any base
    }
    public static void main(String[] args) {

    }
}
