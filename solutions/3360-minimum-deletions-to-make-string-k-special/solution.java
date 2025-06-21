class Solution {
    public static int minimumDeletions(String word, int k) {
        int countMin = word.length();
        HashMap<Character, Integer> freq = new HashMap<>();
        for (int i = 0; i < word.length(); i++) {
            if(!freq.containsKey(word.charAt(i))) freq.put(word.charAt(i), 1);

            else {
                int value = freq.get(word.charAt(i));
                freq.replace(word.charAt(i), value, value+1);
            }
        }
        for (Integer value : freq.values()) {
            int countDel = 0;
            for (Integer val : freq.values()) {
                if(value>val) countDel = countDel+val;
                else if(value+k<val){
                    countDel = countDel+val-value-k;
                }
            }
            if(countDel<countMin) countMin = countDel;
        }
        return countMin;
    }
}
