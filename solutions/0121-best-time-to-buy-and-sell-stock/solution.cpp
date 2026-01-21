class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> diff;
        for(int i = 1;i<prices.size();i++){
            diff.push_back(prices[i]-prices[i-1]);
        }
        int sum = 0;
        int maxSum = 0;
        for(int i = 0;i<diff.size();i++){
            sum+=diff[i];
            if(sum<0) sum = 0;
            if(sum>maxSum) maxSum = sum;
        }
        return maxSum;
    }
};
