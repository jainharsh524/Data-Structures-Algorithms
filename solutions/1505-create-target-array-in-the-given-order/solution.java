class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        ArrayList <Integer> list = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            list.add(index[i],nums[i]);
        }
        int[] nums1 = new int[nums.length];
        for(int i =0;i< nums.length;i++){
            nums1[i] = list.get(i);
        }
        return nums1;
    }
}
