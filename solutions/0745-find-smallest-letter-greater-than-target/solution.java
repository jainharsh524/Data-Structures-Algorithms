class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        if(target>=letters[letters.length-1]) return letters[0];
        else {
            int low = 0;
            int high = letters.length - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                // if (letters[mid] == target) return letters[mid];
                if (letters[mid] > target) high = mid - 1;
                else low = mid + 1;
            }
            return letters[low];
        }
    }
}
