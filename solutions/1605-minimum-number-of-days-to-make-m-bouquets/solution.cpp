class Solution {
public:
    int calBouquets(vector<int>& bloomDay, int k, int day){
        int adj = 0;
        int count = 0;
        for(int i = 0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                adj++;
            }
            else adj = 0;
            if(adj==k){
                count++;
                adj = 0;
            }
        }
        return count;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // if((m*k)>bloomDay.size()) return -1;
        int maxi = -1;
        int l = *min_element(bloomDay.begin(), bloomDay.end());;
        for(int ele: bloomDay) maxi = max(maxi, ele);
        int mindays = -1;
        while(l<=maxi){
            int mid = l+(maxi-l)/2;
            int bouquets = calBouquets(bloomDay, k, mid);
            if(bouquets<m) l = mid+1;
            else{
                maxi = mid-1;
                mindays = mid;
            }
        }
        return mindays;
    }
};
