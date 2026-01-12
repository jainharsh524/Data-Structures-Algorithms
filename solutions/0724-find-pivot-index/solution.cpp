class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> pre(nums.size(), 0);
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum = sum+nums[i];
            pre[i] = sum;
        }
        for(int i = 0;i<nums.size();i++){
            int stn = pre[i]-nums[i];
            if(stn==pre[nums.size()-1]-pre[i]) return i;
        }
        return -1;
    }
};
