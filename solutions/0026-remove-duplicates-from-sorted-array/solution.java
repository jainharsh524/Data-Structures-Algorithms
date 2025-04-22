class Solution {
    public static int[] swap (int[] arr, int index1, int index2){
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
        return arr;
    }
    public int removeDuplicates(int[] nums) {
       int lastUniqueIndex = 0;
        for(int i = 1;i< nums.length;i++){
            if(nums[i] != nums[lastUniqueIndex]){
//                ++lastUniqueIndex;
                nums = swap(nums, i, lastUniqueIndex+1);
                lastUniqueIndex++;
            }
        }
        // System.out.println(Arrays.toString(nums));
        return lastUniqueIndex+1; 
    }
}
