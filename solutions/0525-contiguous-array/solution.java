class Solution {
    public static int findMaxLength(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            if(nums[i]==0) nums[i]=-1;
        }
        HashMap<Integer, Integer> hm = new HashMap<>();
        int sum = 0;
        int j =0;
        int maxLen = 0;
        for (int i = 0; i < nums.length; i++) {
            int len = 0;
            sum += nums[i];
            if(sum == 0){
                maxLen = i + 1;
            }
            else{
                if(hm.containsKey(sum)){
                    j = hm.get(sum);
                    len = i - j;
                    if(len>maxLen) {
                        maxLen = len;
                    }
                }
                else hm.put(sum, i);
            }
        }
        return maxLen;
    }
}
