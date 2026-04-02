class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1){
            return true;
        }
        int sz = nums.size()-1;
        vector<bool> dp(sz, false);
        dp[sz] = true;
        for(int i = sz-1;i>=0;i--){
            if(nums[i]==0) dp[i] = false;
            else{
                for(int j = 1;j<=nums[i];j++){
                    if((i+j<=sz)&&dp[i+j]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};
