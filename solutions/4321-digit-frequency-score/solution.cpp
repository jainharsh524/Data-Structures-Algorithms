class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int, int> mp;
        int ele = n;
        while(ele>0){
            int rem = ele%10;
            mp[rem]++;
            ele = ele/10;
        }
        int sum = 0;
        for(auto pr: mp){
            sum = sum+(pr.first*pr.second);
        }
        return sum;
    }
};
