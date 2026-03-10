class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;

        for (auto& s : stones) {
            pq.push(s);
        }

        while(pq.size() > 1){

            int mx1 = 0, mx2 = 0;
            mx1 = pq.top();
            pq.pop();
            mx2 = pq.top();
            pq.pop();
            
            if(mx1 != mx2){
                pq.push(mx1 - mx2);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};
