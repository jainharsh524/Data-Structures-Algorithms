class Solution {
    public static int numSub(String s) {
        long countOne = 0;
        long subStrings = 0;
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i)=='1'){
                countOne++;
            }
            else {
                long val = countOne*(countOne+1)/2;
                subStrings = subStrings+val;
                countOne=0;
            }
        }
        if(countOne!=0) {
            long val = countOne*(countOne+1)/2;
            subStrings = subStrings+val;
        }
        return (int) (subStrings%(Math.pow(10,9)+7));
    }
}
