class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] array = new int[2];
        HashMap<Integer, Integer> hm = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            hm.put(nums[i],i);
        }
        for (int i = 0; i < nums.length; i++) {
            int element = nums[i];
            int newTarget = target-element;
            if(hm.containsKey(newTarget)){
                int index = hm.get(newTarget);
                if(index!=i){
                    array[0] = i;
                    array[1] = index;
                }
            }
        }
        return array;
    }
}
