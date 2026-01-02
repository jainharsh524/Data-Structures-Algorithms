class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;int j = nums.size()-1;
        while(i<=j){
            if(nums[i]==val&&nums[j]!=val){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j--;i++;
            }
            if(nums[j]==val) j--;
            if(nums[i]!=val) i++;
        }
        return i;
    }
};
