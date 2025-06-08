class Solution {
    public boolean isPowerOfThree(int n) {
        double log3_x = Math.log10(n)/Math.log10(3);
        String str = String.valueOf(log3_x);
        if(str.charAt(str.length()-1)=='0'&&str.charAt(str.length()-2)=='.') return true;
        else return false;
    }
}
