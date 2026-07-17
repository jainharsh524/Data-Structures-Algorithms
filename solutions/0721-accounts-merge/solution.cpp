class DS{
public:
    vector<int> rank, parent;
    DS(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find_ult_par(int node){
        if(node==parent[node]) return node;
        return parent[node]=find_ult_par(parent[node]);
    }
    void unionByRank(int u,int v){
        int pu=find_ult_par(u);
        int pv=find_ult_par(v);
        if(pu==pv) return;
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else if(rank[pv]>rank[pu]){
            parent[pu]=pv;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DS ds(accounts.size());
        unordered_map<string,int> mp;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j])==mp.end()){
                    mp[accounts[i][j]]=i;
                }
                else{
                    ds.unionByRank(i, mp[accounts[i][j]]);
                }
            }
        }
        vector<vector<string>> mails(accounts.size());
        for(auto &it: mp){
            string mail=it.first;
            int node=it.second;
            int parent=ds.find_ult_par(node);
            mails[parent].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<accounts.size();i++){
            if(mails[i].empty()) continue;
            sort(mails[i].begin(), mails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto &mail:mails[i]) temp.push_back(mail);
            ans.push_back(temp);
        }
        return ans;
    }
};
