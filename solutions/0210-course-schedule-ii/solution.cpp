class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++) indeg[prerequisites[i][0]]++;
        vector<vector<int>> adj_lst(numCourses);
        for(int i = 0; i < prerequisites.size(); i++) adj_lst[prerequisites[i][1]].push_back(prerequisites[i][0]);
        queue<int> q;
        for(int i = 0; i < numCourses; i++) if(indeg[i] == 0) q.push(i);
        vector<int> res;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int nei : adj_lst[node]){
                indeg[nei]--;
                if(indeg[nei] == 0) q.push(nei);
            }
        }
        if(res.size() != numCourses) return {};
        return res;
    }
};
