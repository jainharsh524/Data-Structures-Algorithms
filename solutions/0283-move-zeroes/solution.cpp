class Solution {
public:
   void swap(vector<int>& nums, int index1, int index2){
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
    void moveZeroes(vector<int>& nums) {
        int li = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums, i, li);
                li++;
            }
        }
    }
};
