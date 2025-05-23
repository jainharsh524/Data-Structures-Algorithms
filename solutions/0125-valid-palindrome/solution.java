class Solution {
    public static boolean isPalindrome(String s) {
        s = s.toLowerCase();
        int i =0;
        int j =s.length()-1;
        while(i<j){
            if((s.charAt(i)>0&&s.charAt(i)<=47)||(s.charAt(i)>=58&&s.charAt(i)<=64)||(s.charAt(i)>=91&&s.charAt(i)<=96)||(s.charAt(i)>=123&&s.charAt(i)<127)){
                i++;
                continue;
            }
            if((s.charAt(j)>0&&s.charAt(j)<=47)||(s.charAt(j)>=58&&s.charAt(j)<=64)||(s.charAt(j)>=91&&s.charAt(j)<=96)||(s.charAt(j)>=123&&s.charAt(j)<127)){
                j--;
            }
            else if(s.charAt(i)==s.charAt(j)){
                i++;j--;
            }
            else if(s.charAt(i)!=s.charAt(j)){
                return false;
            }
        }
        return true;
    }
}
