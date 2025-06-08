class Solution {
    public boolean isPowerOfFour(int n) {
        double log4_x = Math.log10(n)/Math.log10(4);
        String str = String.valueOf(log4_x);
        if(str.charAt(str.length()-1)=='0'&&str.charAt(str.length()-2)=='.') return true;
        else return false;
    }
}
