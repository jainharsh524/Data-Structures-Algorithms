class Solution {
    public static boolean checkSubarraySum(int[] nums, int k) {
        HashMap<Integer, Integer> hm = new HashMap<>();
        hm.put(0, -1);
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum+=nums[i];
            int rem = sum%k;
            if(hm.containsKey(rem)&&i-hm.get(rem)>=2){
                return true;
            }
            else if(!hm.containsKey(rem))hm.put(rem, i);
        }
        return false;
    }
}
