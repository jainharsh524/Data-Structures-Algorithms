class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = 0;
        for(int i = 0;i<nums.size();i++){
            if(goal >= i) goal = max(nums[i]+i, goal);
            else return false;
        }
        return true;
    }
};
