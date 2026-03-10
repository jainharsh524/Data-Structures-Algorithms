class Solution {
public:
    double caldist(vector<int> coord){
        int x = coord[0];
        int y = coord[1];
        return sqrt(x*x+y*y);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>>> pq;
        for(int i = 0;i<points.size();i++){
            pq.push({caldist(points[i]), points[i]});
        }
        for(int i = 0;i<k;i++){
            res.push_back(pq.top().second);pq.pop();
        }
        return res;
    }
};
