class Solution {
    public int minDeletion(String s, int k) {
        if (k == 0) return s.length();
        Map<Character, Integer> freqMap = new HashMap<>();
        for (char ch : s.toCharArray()) {
            freqMap.put(ch, freqMap.getOrDefault(ch, 0) + 1);
        }
        if (freqMap.size() <= k) return 0;
        List<Integer> freqList = new ArrayList<>(freqMap.values());
        Collections.sort(freqList);
        int deletions = 0;
        int removeCount = freqList.size() - k;

        for (int i = 0; i < removeCount; i++) {
            deletions += freqList.get(i);
        }
        return deletions;
        
    }
}
