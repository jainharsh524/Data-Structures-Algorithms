class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size(), 1);
        pre[0] = nums[0];
        for(int i = 1;i<nums.size();i++){
            pre[i] = nums[i] * pre[i-1];
        } 
        vector<int> suff(nums.size(), 1);
        suff[nums.size()-1] = nums[nums.size()-1];
        for(int i = nums.size()-2;i > 0;i--){
            suff[i] = nums[i] * suff[i+1];
        }
        vector<int> res(nums.size(), 1);
        for(int i = 0;i < nums.size();i++){
            int ptr1 = i-1;
            int ptr2 = i+1;
            int val1 = ptr1 >= 0 ? pre[ptr1] : 1;
            int val2 = ptr2 <= nums.size()-1 ? suff[ptr2] : 1;
            res[i] = val1*val2;
        }
        return res;
    }
};
