class Solution {
public:
    int maxArea(vector<int>& nums) {
        int i = 0;int j = nums.size()-1;
        int maxArea = 0;
        while(i<j){
            int mH = min(nums[i], nums[j]);
            int area = mH*(j-i);
            if(area>maxArea) maxArea = area;
            if(nums[i]>nums[j])j--;
            else i++;
        }
        return maxArea;
    }
};
