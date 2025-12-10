class Solution {
public:
    double dfs(int qnode1, int qnode2, vector<vector<pair<int, double>>> adj_lst, vector<int> &visited){
        visited[qnode1] = 1;
        double res = 1.0;
        for(auto &iter: adj_lst[qnode1]){
            int nn = iter.first;
            double wt = iter.second;
            if(nn==qnode2){
                return res*wt;
            }
            else if(visited[nn]==0){
                double div = dfs(nn, qnode2, adj_lst, visited);
                if(div!=-1.0) {
                    res = res*div*wt;
                    return res;
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
       unordered_map<string, int> mp;
        int idx = 0;

        // Assign an index to each variable
        for (int i = 0; i < (int)equations.size(); i++) {
            const string &a = equations[i][0];
            const string &b = equations[i][1];

            if (!mp.count(a)) mp[a] = idx++;
            if (!mp.count(b)) mp[b] = idx++;
        }
        vector<vector<pair<int, double>>> adj_lst(idx);
        for(int i = 0;i<equations.size();i++){
            adj_lst[mp[equations[i][0]]].push_back({mp[equations[i][1]], values[i]});
            adj_lst[mp[equations[i][1]]].push_back({mp[equations[i][0]], 1/values[i]});
        }
        for(int i = 0;i<queries.size();i++){
            const string &s = queries[i][0];
            const string &t = queries[i][1];

            if (!mp.count(s) || !mp.count(t)) {
                ans.push_back(-1.0);
                continue;
            }

            int node1 = mp[s];
            int node2 = mp[t];
            if(node1==node2) ans.push_back(1);
            else{
                vector<int> visited(idx, 0);
                double res = dfs(node1, node2, adj_lst, visited);
                ans.push_back(res);
            }
        }
        return ans;
    }
};
