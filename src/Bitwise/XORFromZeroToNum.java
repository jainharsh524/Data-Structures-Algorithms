package Bitwise;

public class XORFromZeroToNum {
    public static int XOR(int num){
        //This is the pattern observed for XOR of continuous numbers from zero.
        if(num%4==0) return num;
        else if (num % 4 == 1) return 1;
        else if (num % 4 == 2) return num+1;
        return 0;
    }
    //XOR from a to b
    public static int XORInRange(int a, int b){
        //If we XOR same numbers the result will be 0.
        return XOR(b) ^ XOR(a-1);
    }
    public static void main(String[] args) {

    }
}
