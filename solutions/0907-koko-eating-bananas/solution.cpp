class Solution {
public:
    int calHour(vector<int>& piles, int k){
        int hrs = 0;
        for (int ele : piles) {
            hrs += (ele + k - 1) / k;   // ceil(ele / k)
        }
        return hrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;
        for(int ele: piles){
            maxi = max(ele, maxi);
        }
        if(h == piles.size()) return maxi;
        int l = 1;
        int r = maxi;
        while(l<r){
            int m = l+(r-l)/2;
            int hrs = calHour(piles, m);
            if(hrs>h) l = m+1;
            else r = m;
        }
        return l;
    }
};
