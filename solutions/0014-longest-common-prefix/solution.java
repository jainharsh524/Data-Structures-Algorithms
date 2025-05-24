class Solution {
    public String longestCommonPrefix(String[] strs) {
        int[] index = new int[strs.length];
        String s = "";
        int minLength = 200;
        for (int j = 0; j < strs.length; j++) {
            if(strs[j].length()<minLength) minLength = strs[j].length();
        }
        boolean flag = false;
        int i = 0;
        while(i<minLength){
            char ch = strs[0].charAt(i);
            for (int j = 0; j < strs.length; j++) {
                if(strs[j].charAt(i)!=ch){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
            s = s+ch;
            i++;
        }
        return s;
    }
}
