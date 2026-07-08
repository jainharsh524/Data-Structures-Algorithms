class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        unordered_map<int, int> mp;
        for(int ele: hand) mp[ele]++;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto ele: mp) pq.push(ele.first);
        while(!pq.empty()){
            int val = pq.top();
            for(int i = val;i<val+groupSize;i++){
                if(mp.find(i)==mp.end()) return false;
                else{
                    mp[i]--;
                    if(mp[i]==0){
                        mp.erase(i);
                        if(pq.top()!=i) return false;
                        else pq.pop();
                    }
                }
            }
        }
        return true;
    }
};
