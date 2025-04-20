class Solution {
    public boolean checkIfPangram(String sentence) {
        HashSet <Character> hs = new HashSet<>();
        for (char i = 0; i < sentence.length(); i++) {
            if(!hs.contains(sentence.charAt(i))) hs.add(sentence.charAt(i));
        }
        return hs.size()==26;
    }
}
