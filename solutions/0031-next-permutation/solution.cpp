class Solution {
public:
    void rev(vector<int> &nums, int index1, int index2){
        int i = index1;int j = index2;
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i++;j--;
    }
    void swap(vector<int> &nums, int index1, int index2){
        int i = index1;int j = index2;
        while(i<j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;j--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int j = nums.size()-1;
        while(j>0&&nums[j-1]>=nums[j]) j--;
        if(j==0) swap(nums, j, nums.size()-1);
        else{
            int i = nums.size()-1;
            while(i>j-1&&nums[j-1]>=nums[i])i--;
            rev(nums, j-1, i);
            swap(nums, j, nums.size()-1);
        }
    }
};
