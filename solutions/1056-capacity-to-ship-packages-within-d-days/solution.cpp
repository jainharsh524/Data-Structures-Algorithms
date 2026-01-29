class Solution {
public:
    int calDays(vector<int> &weights, int cap){
        int currSum = 0;
        int days = 0;
        for(int ele: weights){
            currSum = currSum+ele;
            if(currSum>cap) {
                currSum = ele;
                days++;
            }
        }
        if(currSum>0) days++;
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int maxi = 0;
        for(int ele: weights){
            sum+=ele;
            maxi = max(ele, maxi);
        }
        if(days==1) return sum;
        int l = maxi;
        int r = sum;
        while(l<r){
            int m = l+(r-l)/2;
            int d = calDays(weights, m);
            if(d>days) l = m+1;
            else r = m;
        }
        return l;
    }
};
