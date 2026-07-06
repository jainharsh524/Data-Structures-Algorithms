class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int window = n - k;
        int total = 0;
        for(int x : cardPoints)
            total += x;
        if(window == 0)
            return total;
        int sum = 0;
        for(int i = 0; i < window; i++)
            sum += cardPoints[i];
        int minWindow = sum;
        for(int r = window; r < n; r++) {
            sum += cardPoints[r];
            sum -= cardPoints[r - window];
            minWindow = min(minWindow, sum);
        }
        return total - minWindow;
    }
};
