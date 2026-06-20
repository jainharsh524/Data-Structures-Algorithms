class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<vector<int>> mp;
        for(int i = 0; i < n; i++) {
            if(lights[i] > 0) {
                int st = max(0, i - lights[i]);
                int en = min(n - 1, i + lights[i]);
                mp.push_back({st, en});
            }
        }
        if(mp.empty()) {
            return (n + 2) / 3;
        }
        sort(mp.begin(), mp.end());
        vector<vector<int>> merged;
        merged.push_back(mp[0]);
        for(int i = 1; i < mp.size(); i++) {
            if(mp[i][0] <= merged.back()[1] + 1) {
                merged.back()[1] =
                    max(merged.back()[1], mp[i][1]);
            } else {
                merged.push_back(mp[i]);
            }
        }
        long long ans = 0;
        int prev = -1;
        for(auto &it : merged) {
            int gapLen = it[0] - prev - 1;
            if(gapLen > 0) {
                ans += (gapLen + 2) / 3;
            }
            prev = it[1];
        }
        int tailGap = n - prev - 1;
        if(tailGap > 0) {
            ans += (tailGap + 2) / 3;
        }
        return ans;
    }
};
