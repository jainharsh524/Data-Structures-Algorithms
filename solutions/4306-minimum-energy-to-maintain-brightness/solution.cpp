class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long bulb = (brightness+2)/3;
        sort(intervals.begin(), intervals.end());
        long long active = 0;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1;i<intervals.size();i++){
            int l = intervals[i][0];
            int r = intervals[i][1];
            if(l<=end+1){
                end = max(end, r);
            }
            else{
                active+=(end-start+1);
                start = l;
                end = r;
            }
        }
        active+=(end-start+1);
        return bulb*active;
    }
};
