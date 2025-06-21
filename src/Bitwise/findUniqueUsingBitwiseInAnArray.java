package Bitwise;

public class findUniqueUsingBitwiseInAnArray {
    //If every element is occurring twice
    public static int findUnique(int[] arr){
        int a = arr[0];
        for (int i = 1; i < arr.length; i++) {
            a = a^arr[i];
        }
        return a;
    }
    //If every element is occurring thrice
    public static int findUniqueInTripleOccurrence(int[] nums){
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (int num : nums) {
                sum += (num >> i) & 1;
            }
            sum %= 3;
//            System.out.println(sum);
            result += (sum << i);
//            System.out.println(result);
        }
        return result;
    }
    public static void main(String[] args) {
        System.out.println(findUniqueInTripleOccurrence(new int[]{1,1,1,3,3,3,4}));
    }
}
