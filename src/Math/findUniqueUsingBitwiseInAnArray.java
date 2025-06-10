package Math;

public class findUniqueUsingBitwiseInAnArray {
    public static int findUnique(int[] arr){
        int a = arr[0];
        for (int i = 1; i < arr.length; i++) {
            a = a^arr[i];
        }
        return a;
    }
    public static void main(String[] args) {
        System.out.println(findUnique(new int[]{1,1,2,3,3,4,4}));
    }
}
