class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int nsz = cardPoints.size() - k - 1;
        int l = 0;
        int sum = 0;
        int minsum = INT_MAX;
        for(int i = 0;i<cardPoints.size();i++){
            sum = sum + cardPoints[i];
            if( i == nsz) minsum = min(sum, minsum);
            else if(i > nsz){
                sum = sum - cardPoints[l];
                l++;
                minsum = min(sum, minsum);
            }
        }
        sum = 0;
        cout<<minsum;
        for(int ele: cardPoints) sum += ele;
        return sum - minsum;
    }
};
