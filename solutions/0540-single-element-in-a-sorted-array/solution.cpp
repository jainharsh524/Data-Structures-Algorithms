class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0,h = nums.size()-1;
        while(l<h){
            int m = l+(h-l)/2;
            if(m>l&&nums[m]==nums[m-1]){
                if((m-l-1)%2!=0) h = m-2;
                else l = m+1;
            }
            else if(m<h&&nums[m]==nums[m+1]){
                if((m-l)%2!=0) h = m-1;
                else l = m+2;
            }
            else return nums[m];
        }
        return nums[l];
    }
};
