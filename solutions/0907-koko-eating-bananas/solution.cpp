class Solution {
public:
    int calHours(vector<int>& piles, int speed){
        int hrs = 0;
        for(int ele: piles){
            hrs+=ele/speed;
            if((ele%speed)>0) hrs++;
        }
        return hrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = -1;
        for(int ele: piles) maxi = max(ele, maxi);
        int l = 1;
        if(h == piles.size()) return maxi;
        while(l<maxi){
            int m = l+(maxi-l)/2;
            int hrs = calHours(piles, m);
            if(hrs>h) l = m+1;
            else maxi = m;
        }
        return l;
    }
};
