class Solution {
    public static void sortColors(int[] nums) {
        HashMap<Integer,Integer> mp = new HashMap<>();
        mp.put(0,0);
        mp.put(1,0);
        mp.put(2,0);
        for (int i = 0; i < nums.length; i++) {
            if(nums[i]==0) mp.replace(0,mp.get(0)+1);
            else if(nums[i]==1) mp.replace(1,mp.get(1)+1);
            else mp.replace(2,mp.get(2)+1);
        }
        int index =0;
        while(mp.get(0)>0){
            nums[index]=0;
            index++;
            mp.replace(0,mp.get(0)-1);
        }
        while(mp.get(1)>0){
            nums[index]=1;
            index++;
            mp.replace(1,mp.get(1)-1);
        }
        while(mp.get(2)>0&&index<nums.length){
            nums[index]=2;
            index++;
            mp.replace(1,mp.get(2)-1);
        }
    }
}
