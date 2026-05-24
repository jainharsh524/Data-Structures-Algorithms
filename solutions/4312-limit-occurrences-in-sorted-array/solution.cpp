class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        if(k==0) return {};
        vector<int> res;
        int cnt = 0;
        int curr = nums[0];
        for(int ele: nums){
            if(ele==curr&&cnt<k){
                res.push_back(ele);
                cnt++;
            }
            else if(ele!=curr){
                curr = ele;
                res.push_back(ele);
                cnt = 1;
            }
        }
        return res;
    }
};
