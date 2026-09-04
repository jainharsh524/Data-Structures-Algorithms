class Solution {
public:
    void generate(int index, int end, long long sum,
                  vector<int>& nums, vector<long long>& sums) {
        if(index == end) {
            sums.push_back(sum);
            return;
        }
        generate(index + 1, end, sum, nums, sums);
        generate(index + 1, end, sum + nums[index], nums, sums);
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int mid = n / 2;
        vector<long long> sumL, sumR;
        generate(0, mid, 0, nums, sumL);
        generate(mid, n, 0, nums, sumR);
        sort(sumR.begin(), sumR.end());
        long long mn = abs((long long)goal);
        for(long long sum : sumL) {
            long long target = (long long)goal - sum;
            auto it = lower_bound(sumR.begin(), sumR.end(), target);
            if(it != sumR.end())
                mn = min(mn, abs(target - *it));
            if(it != sumR.begin())
                mn = min(mn, abs(target - *prev(it)));
            if(mn == 0)
                return 0;
        }
        return mn;
    }
};
