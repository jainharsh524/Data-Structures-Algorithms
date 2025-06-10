package Math;

public class ithBitOfANumberInBinary {
    public static int findIThBit(int n, int i){
        return n&(1<<(i-1));//masking with i-1 zeroes
    }
    public static int setIThBit(int n, int i){
        return n|(1<<(i-1));
    }
    public static void main(String[] args) {
        System.out.println(findIThBit(55,4));
        System.out.println(setIThBit(55,4));
    }
}
