class Solution {
public:
    unordered_map<int, vector<string>> caldist(string bW, vector<string>& wordList){
        unordered_map<int, vector<string>> dist;
        for(string &ele: wordList){
            int cnt = 0;
            for(int i = 0;i<ele.size();i++){
                if(ele[i]!=bW[i]) cnt++;
            }
            dist[cnt].push_back(ele);
        }
        return dist;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue <pair<string, int>> q;
        unordered_map<int, vector<string>> mp = caldist(beginWord, wordList);
        unordered_map<string, int> visited;
        for(int i = 0;i<mp[1].size();i++){
            q.push({mp[1][i], 1});
            visited[mp[1][i]] = 1;
            // cout<<mp[1][i]<<endl;
        }

        while(!q.empty()){
            string ele = q.front().first;
            int dist = q.front().second;
            q.pop();
            cout<<ele<<" "<<dist<<endl;
            if(ele==endWord) return dist+1;
            else{
                mp = caldist(ele, wordList);
                for(int i = 0;i<mp[1].size();i++){
                    if(visited.find(mp[1][i])==visited.end()) {
                        q.push({mp[1][i], dist+1});
                        visited[mp[1][i]] = 1;
                    }
                    // cout<<mp[1][i]<<endl;
                }
            }
        }
        return 0;
    }
};
