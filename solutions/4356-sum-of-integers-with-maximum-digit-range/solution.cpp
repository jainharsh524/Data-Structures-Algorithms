class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        priority_queue<pair<int,int>> pq;
        for(int ele : nums){
            int x = ele;
            int maxdig = 0;
            int mindig = 9;
            while(x > 0){
                int dig = x % 10;
                maxdig = max(maxdig, dig);
                mindig = min(mindig, dig);
                x /= 10;
            }
            int range = maxdig - mindig;
            pq.push({range, ele});
        }
        int maxval = pq.top().first;
        int sum = 0;
        while(!pq.empty() && pq.top().first == maxval){
            sum += pq.top().second;
            pq.pop();
        }
        return sum;
    }
};
