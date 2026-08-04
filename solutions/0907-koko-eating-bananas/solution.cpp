class Solution {
public:
    long long calTime(vector<int>& piles, long long cap){
        long long cnt = 0;
        for(long long ele: piles){
            cnt += ele/cap;
            if(ele%cap!=0) cnt++;
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, long long h) {
        long long l = 1;
        long long maxi = piles[0];
        for(long long ele: piles) maxi = max(maxi, ele);
        long long r = maxi;
        while(l<=r){
            long long mid = l+(r-l)/2;
            long long hrs = calTime(piles, mid);
            if(hrs>h) l = mid+1;
            else r = mid-1;
        }
        return int(l);
    }
};
