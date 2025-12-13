class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int> outdegree(nodes, 0);
        vector<int> res;
        vector<vector<int>> revg(nodes);
        for(int i =0;i<nodes;i++){
            outdegree[i] = graph[i].size();
        }
        queue<int> q;
        for(int i =0;i<nodes;i++){
            if(outdegree[i]==0){
                q.push(i);
            }
        }
        for(int i = 0;i<graph.size();i++){
            for(int j = 0;j<graph[i].size();j++){
                revg[graph[i][j]].push_back(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int nn: revg[node]){
                outdegree[nn]--;
                if(outdegree[nn]==0){
                    q.push(nn);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
