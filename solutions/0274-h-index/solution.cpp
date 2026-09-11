class Solution {
public:
    int eBT(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size() - 1;
        while(l<=r){
            int mid = (l + r)/2;
            if(target > nums[mid]) l = mid + 1;
            else r = mid - 1;
        }
        return nums.size() - l;
    }
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int l = 1;
        int r = 1000;
        while(l <= r){
            int mid = (l + r)/2;
            int big = eBT(citations, mid);
            if(big<mid) r = mid - 1;
            else l = mid + 1;
        }
        return r;
    }
};
