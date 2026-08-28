class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(),
        [](vector<int> &a, vector<int>& b){
            return a[0]<b[0];
        });
        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> res;
        for(int i= 1;i<intervals.size();i++){
            int ns = intervals[i][0];
            int ne = intervals[i][1];
            if(end >= ns){
                end = max(end, ne);
                start = min(start, ns);
            }
            else{
                res.push_back({start, end});
                start = ns;
                end = ne;
            }
        }
        res.push_back({start, end});
        return res;
    }
};
