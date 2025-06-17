class Solution {
    public static int hammingWeight(int num) {
        int count = 0;
        while (num>0){
            int end = num&1;
            if(end==1) count++;
            num = num>>1;
        }
        return count;
    }
    public static int hammingDistance(int x, int y) {
        int a = x^y;
        return hammingWeight(a);
    }
}
