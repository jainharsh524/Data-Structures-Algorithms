class Solution {
public:
    int dist(int a, int b, int k){
        int diff = abs(a-b);
        return min(diff, k-diff);
    }
    int minOperations(vector<int>& nums, int k) {
        vector<int> evcost(k, 0);
        vector<int> oddcost(k, 0);
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int rem = nums[i]%k;
            for(int target = 0;target<k;target++){
                int cost = dist(rem, target, k);
                if(i%2==0) evcost[target]+=cost;
                else oddcost[target]+=cost;
            }
        }
        int ans = INT_MAX;
        for(int i = 0;i<k;i++){
            for(int j = 0;j<k;j++){
                if(i==j) continue;
                ans = min(ans, evcost[i]+oddcost[j]);
            }
        }
        return ans;
    }
};
