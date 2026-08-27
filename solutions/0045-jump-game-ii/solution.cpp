class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int goal = 0;
        int farthest = 0;
        for(int i = 0;i<nums.size()-1;i++){
            farthest = max(farthest, i + nums[i]);
            if(goal == i){
                goal = farthest;
                count++;
            }
        }
        return count;
    }
};
