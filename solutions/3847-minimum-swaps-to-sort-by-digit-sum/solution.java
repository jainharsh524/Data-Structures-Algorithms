class Solution {
 public static int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

public int minSwaps(int[] nums) {
    int n = nums.length;
    Pair[] pairs = new Pair[n];

    for (int i = 0; i < n; i++) {
        pairs[i] = new Pair(nums[i], sumOfDigits(nums[i]), i);
    }

    Arrays.sort(pairs, (a, b) -> {
        if (a.digitSum != b.digitSum) return a.digitSum - b.digitSum;
        return a.value - b.value;
    });

    boolean[] visited = new boolean[n];
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || pairs[i].originalIndex == i) continue;

        int cycleSize = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = true;
            j = pairs[j].originalIndex;
            cycleSize++;
        }

        if (cycleSize > 1) swaps += (cycleSize - 1);
    }

    return swaps;
}
static class Pair {
    int value;
    int digitSum;
    int originalIndex;

    Pair(int value, int digitSum, int originalIndex) {
        this.value = value;
        this.digitSum = digitSum;
        this.originalIndex = originalIndex;
    }
}
}
