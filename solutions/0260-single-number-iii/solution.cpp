class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long int xorval = 0;
        for(int ele: nums) xorval^=ele;
        xorval = xorval & (-xorval);
        vector<int> res = {0, 0};
        for(int ele: nums){
            if((ele & xorval)==0) res[0]^=ele;
            else res[1]^=ele;
        }
        return res;
    }
};
