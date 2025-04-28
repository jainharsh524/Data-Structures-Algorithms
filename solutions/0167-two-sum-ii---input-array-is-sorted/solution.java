class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int low = 0;
        int high = numbers.length - 1;
        while (low < high) {
            int Sum = numbers[low] + numbers[high];
            if (Sum == target) return new int[]{low + 1, high + 1};
            else if (Sum > target) high--;
            else low++;
        }
        return new int[]{-1, -1};
    }
}
