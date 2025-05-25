class Solution {
    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> lst = new ArrayList<>();
        String y = String.valueOf(x);
        for (int i = 0; i < words.length; i++) {
            if(words[i].contains(y)) lst.add(i);
        }
        return lst;
    }
}
