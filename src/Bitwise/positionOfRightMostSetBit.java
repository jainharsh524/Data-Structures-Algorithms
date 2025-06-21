package Bitwise;

public class positionOfRightMostSetBit {
    public static int positionOfRightMostSetBit(int n) {
        System.out.println(n&(-n)); //Binary conversion of -n will be in the form of 2's compliment
        //In 2's compliment digits till rightmost 1 bit is same and then rest all are inverted.
        //That's why we are taking and with -n.
        return (int) (Math.log(n&(-n))/Math.log10(2));
        //why 2's compliment represents negative numbers:
        //whenever we subtract a number from zero we get negative number
        //so let's say 10100010 is our number, and we are subtracting it from zero and
        //in binary, if we are using 8-bit number system then if any number have more than 8 bit they get discarded
        //so if we subtract 1,00000000-10100010 the 1 at 9th position will be ignored and technically this will be subtraction by zero
        //we can write above expression as (11111111+1)-10100010 or 11111111-10100010+1
        //11111111-10100010 this is inversion of all the bits.
        //if we add 1 to the result we will get same bits from right as original number until we hit the set bit or 1 bit.
    }

    public static void main(String[] args) {
        System.out.println(positionOfRightMostSetBit(5));
    }
}
