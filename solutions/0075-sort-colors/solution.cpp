class Solution {
public:
    void swap(vector<int> &nums, int index1, int index2){
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = nums.size()-1;
        int high = nums.size()-1;
        while(low<=mid){
            if(nums[mid]==0){
                swap(nums, low, mid);
                low++;
            }
            else if(nums[mid]==2){
                swap(nums, mid, high);
                high--;
                mid--;
            }
            else{
                mid--;
            }
        }
    }
};
