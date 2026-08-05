class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> outdeg(graph.size());
        for(int i = 0;i<graph.size();i++){
            outdeg[i] = graph[i].size();
        }
        queue<int> q;
        for(int i = 0;i<graph.size();i++){
            if(outdeg[i]==0) q.push(i);
        }
        vector<vector<int>> rev_adj(graph.size());
        for(int i = 0;i<graph.size();i++){
            for(int ele: graph[i]){
                rev_adj[ele].push_back(i);
            }
        }
        vector<int> res;
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            res.push_back(ele);
            for(int nei: rev_adj[ele]){
                outdeg[nei]--;
                if(outdeg[nei]==0) q.push(nei);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
