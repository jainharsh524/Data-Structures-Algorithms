class Solution {
    public static boolean areSentencesSimilar(String sentence1, String sentence2) {
        if (sentence1.length() < sentence2.length()) {
            return areSentencesSimilar(sentence2, sentence1);
        }
        String[] words1 = sentence1.split(" ");
        String[] words2 = sentence2.split(" ");
        int i = 0;
        while (i < words2.length && words1[i].equals(words2[i])) i++;
        int j = 0;
        while (j < words2.length - i && words1[words1.length - 1 - j].equals(words2[words2.length - 1 - j])) j++;
        return i + j == words2.length;
    }
}
