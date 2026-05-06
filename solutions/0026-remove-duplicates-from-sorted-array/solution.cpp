class Solution {
public:
    void swap(vector<int>& nums, int index1, int index2){
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
    int removeDuplicates(vector<int>& nums) {
        int lu = 0;
        for(int i = 1;i<nums.size();i++){
            if(nums[i]>nums[lu]){
                swap(nums, i, lu+1);
                lu = lu+1;
            }
        }
        return lu+1;
    }
};
