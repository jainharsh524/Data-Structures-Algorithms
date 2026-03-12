class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> mp;
        for(char &ch: tasks){
            mp[ch]++;
        }
        priority_queue<int> pq;
        // int cnt = 0;
        for(auto it = mp.begin(); it != mp.end(); ) {
            pq.push(it->second);
            it++;
        }
        int tm = 0;
        while(!pq.empty()){
            vector<int> rem;
            int count = n+1;
            while(count&&!pq.empty()){
                int mf = pq.top();
                pq.pop();
                if(mf>1){
                    rem.push_back(mf-1);
                }
                tm++;
                count--;
            }
            for(int i = 0;i<rem.size();i++){
                pq.push(rem[i]);
            }
            if(pq.empty()) break;
            tm = tm+count;
        }
        return tm;
    }
};
