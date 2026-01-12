class Solution {
public:
    void swap(vector<int>&nums, int index1, int index2){
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
    int removeDuplicates(vector<int>& nums) {
        int lastUnique = 1;
        // int curr = 0;
        for(int i = 1;i<nums.size();i++){
            if(nums[i]!=nums[lastUnique-1]){
                swap(nums, lastUnique, i);
                // cout<<lastUnique<<endl;
                lastUnique++;
            }
        }
        return lastUnique;
    }
};
