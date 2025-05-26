class Solution {
    public static boolean isPalindrome(String s, int left, int right) {
        while (left < right) {
            if (s.charAt(left++) != s.charAt(right--)) return false;
        }
        return true;
    }

    public static boolean check(String a, String b) {
        int i = 0, j = b.length() - 1;
        while (i < j && a.charAt(i) == b.charAt(j)) {
            i++;
            j--;
        }
        return isPalindrome(a, i, j) || isPalindrome(b, i, j);
    }

    public static boolean checkPalindromeFormation(String a, String b) {
        return check(a, b) || check(b, a);
    }
}
