class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        priority_queue<pair<int,char>> pq;
        for(char &ch: s){
            mp[ch]++;
        }
        for(auto &ele: mp){
            pq.push({ele.second, ele.first});
        }
        string res = "";
        while(!pq.empty()){
            vector<pair<int, char>> rem;
            int cnt = 2;
            while(cnt&&!pq.empty()){
                int mf = pq.top().first;
                char c = pq.top().second;
                if(mf>1){
                    rem.push_back({pq.top().first-1, pq.top().second});
                }
                cnt--;
                pq.pop();
                res = res+c;
            }
            for(auto &ele: rem){
                pq.push(ele);
            }
        }
        for(int i = 1;i<res.size();i++){
            if(res[i]==res[i-1]) return "";
        }
        return res;
    }
};
