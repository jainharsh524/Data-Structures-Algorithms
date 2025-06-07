class Solution {
    public boolean isPowerOfTwo(int n) {
        double log2_x = Math.log10(n)/Math.log10(2);
        String str = String.valueOf(log2_x);
        if(str.charAt(str.length()-1)=='0'&&str.charAt(str.length()-2)=='.') return true;
        else return false;
    }
}
