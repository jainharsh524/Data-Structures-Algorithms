class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int jumps = 0;
        while(r<nums.size()-1){
            int maxgoal = l;
            for(int i = l;i<=r;i++){
                maxgoal = max(maxgoal, nums[i]+i);
            }
            l = r+1;
            jumps++;
            r = maxgoal;
        }
        return jumps;
    }
};
