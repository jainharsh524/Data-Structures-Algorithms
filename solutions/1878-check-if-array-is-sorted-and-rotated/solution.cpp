class Solution {
public:
    bool check(vector<int>& nums) {
        int mini = INT_MAX;
        int minIndex = -1;
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                minIndex = i+1;
                break;
            }
        }
        if(minIndex==-1) return true;
        else if(nums[0]>=nums[nums.size()-1]){
            bool flag = true;
            for(int i = 1;i<minIndex;i++){
                if(nums[i]<nums[i-1]) {
                    flag = false;
                    break;
                }
            }
            for(int i = minIndex+1;i<nums.size();i++){
                if(nums[i]<nums[i-1]) {
                    flag = false;
                    break;
                }
            }
            return flag;
        }
        else return false;
    }
};
