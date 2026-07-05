class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int count = 0;
        int maxlen = 0;
        int r = 0;
        for(r = 0;r<nums.size();r++){
            if(nums[r]==0){
                count++;
            }
            maxlen = max(r-l, maxlen);
            while(count>k){
                if(nums[l]==0) count--;
                l++;
            }
        }
        maxlen = max(maxlen, r-l);
        return maxlen;
    }
};
