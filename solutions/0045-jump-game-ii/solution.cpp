class Solution {
public:
    int jump(vector<int>& nums) {
        int sz = nums.size();
        vector<int> dp(sz, INT_MAX);
        dp[sz-1]=0;
        int goal = sz-1;
        for(int i = sz-2;i>=0;i--){
            if((i+nums[i])>=sz-1){
                dp[i] = 1;
                goal = min(goal, i);
                // cout<<i<<endl;
            }
            else{
                int mini = INT_MAX;
                for(int j = nums[i];j>0;j--){
                    mini = min(mini, dp[i+j]);
                    // cout<<mini<<endl;
                }
                if(mini!=INT_MAX) dp[i] = 1+mini;
            }
        }
        return dp[0];
    }
};
