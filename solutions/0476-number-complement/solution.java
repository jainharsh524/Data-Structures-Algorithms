class Solution {
    public static int findComplement(int num) {
        int dig = (int) (Math.log(num)/Math.log(2))+1;
        int b = (int) (Math.pow(2, dig)-1);
        return num^b;
    }
}
