class Solution {
    public static int countConsistentStrings(String allowed, String[] words) {
        int count = 0;
        HashSet<Character> charArray = new HashSet<>();
        for (int i = 0; i < allowed.length(); i++) {
            charArray.add(allowed.charAt(i));
        }
        for (int i = 0; i < words.length; i++) {
            boolean flag = true;
            for (int j = 0; j < words[i].length(); j++) {
                if (!charArray.contains(words[i].charAt(j))) {
                    flag = false;
                }
            }
            if(flag) count++;
        }
        return count;
    }
}
