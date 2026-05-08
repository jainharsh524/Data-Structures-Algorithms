class Solution {
public:
    void swap(vector<int> &nums, int index1, int index2){
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
    void rev(vector<int> &nums, int start, int end){
        while(start < end){
            swap(nums, start, end);
            start++;
            end--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while(i > 0 && nums[i] <= nums[i - 1]){
            i--;
        }
        if(i == 0){
            rev(nums, 0, nums.size() - 1);
        }
        else{
            int j = nums.size() - 1;
            while(nums[j] <= nums[i - 1]){
                j--;
            }
            swap(nums, i - 1, j);
            rev(nums, i, nums.size() - 1);
        }
    }
};
