class Solution {
public:
    int val(vector<int>& nums, vector<int>& dp, int curr, int last){
        if(curr >= last) return 0;
        if(dp[curr] != -1) return dp[curr];
        int take = nums[curr] + val(nums, dp, curr + 2, last);
        int skip = val(nums, dp, curr + 1, last);
        return dp[curr] = max(take, skip);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp1(nums.size(), -1);
        vector<int> dp2(nums.size(), -1);
        return max(val(nums, dp1, 0, nums.size() - 1), val(nums, dp2, 1, nums.size()));
    }
};
