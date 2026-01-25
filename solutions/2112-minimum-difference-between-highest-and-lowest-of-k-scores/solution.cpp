class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(nums.size()==1) return 0;
        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;
        int left = 0;
        int count = k;
        int mini = INT_MAX;int maxi = INT_MIN;
        for(int right = 0;right<nums.size();right++){
            // mini = min(nums[right], mini);
            // maxi = max(nums[right], maxi);
            if(right-left+1==count){
                minDiff = min(nums[right]-nums[left], minDiff);
                left++;
            }
        }
        return minDiff;
    }
};
