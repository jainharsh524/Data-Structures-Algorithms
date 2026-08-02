class Solution {
public:
    int daycal(vector<int>& weights, int capacity){
        int sum = 0;
        int cntdays = 0;
        for(int ele: weights){
            sum+=ele;
            if(sum>capacity){
                sum = ele;
                cntdays++;
            }
        }
        if(sum==0) return cntdays;
        else return cntdays+1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = 0;
        int sum = 0;
        for(int ele: weights) maxi = max(maxi, ele);
        for(int ele: weights) sum+=ele;
        int l = maxi;
        int r = sum;
        int ans = sum;
        while(l<r){
            int midcap = l+(r-l)/2;
            int day = daycal(weights, midcap);
            // cout<<midcap<<" "<<l<<" "<<r<<" "<<day<<endl;
            if(day>days) {
                l = midcap+1;
            }
            else {
                ans = min(ans, midcap);
                r = midcap;
            }
        }
        return ans;
    }
};
