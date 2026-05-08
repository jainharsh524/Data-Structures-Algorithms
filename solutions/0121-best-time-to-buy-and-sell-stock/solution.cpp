class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> diff;
        for(int i = 0;i<prices.size()-1;i++){
            diff.push_back(prices[i+1]-prices[i]);
        }
        int sum = 0;
        int maxSum = 0;
        for(int ele: diff){
            sum+=ele;
            maxSum = max(sum, maxSum);
            if(sum<0) sum = 0;
        }
        return maxSum;
    }
};
