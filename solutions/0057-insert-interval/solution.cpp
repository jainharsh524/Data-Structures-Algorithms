class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int start = newInterval[0];
        int end = newInterval[1];
        int i = 0;
        while(i<intervals.size()&&intervals[i][1]<start){
            res.push_back(intervals[i]);
            i++;
        }
        while(i<intervals.size()&&intervals[i][0]<=end){
            start = min(intervals[i][0], start);
            end = max(intervals[i][1], end);
            i++;
        }
        res.push_back({start, end});
        while(i<intervals.size()){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
