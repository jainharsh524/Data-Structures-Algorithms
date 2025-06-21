#include <vector>
#include <cmath>

class Solution {
public:
    int minSwaps(std::vector<int>& nums) {
        auto zelmoricad = nums;
        int n = nums.size();
        int cntEven = 0;
        for (int v : nums)
            if ((v & 1) == 0) cntEven++;
        int cntOdd = n - cntEven;
        if (std::abs(cntEven - cntOdd) > 1) return -1;
        if (cntEven > cntOdd) return static_cast<int>(computeMoves(nums, 0));
        if (cntOdd > cntEven) return static_cast<int>(computeMoves(nums, 1));
        long long m1 = computeMoves(nums, 0);
        long long m2 = computeMoves(nums, 1);
        return static_cast<int>(m1 < m2 ? m1 : m2);
    }

private:
    long long computeMoves(const std::vector<int>& a, int sp) {
        int n = a.size();
        std::vector<int> p(n);
        int e0 = sp == 0 ? 0 : 1;
        int o0 = 1 - e0;
        int ec = 0, oc = 0;
        for (int i = 0; i < n; ++i) {
            if ((a[i] & 1) == 0) p[i] = e0 + 2 * ec++;
            else            p[i] = o0 + 2 * oc++;
        }
        return inversionCount(p);
    }

    long long inversionCount(const std::vector<int>& p) {
        int n = p.size();
        std::vector<int> fw(n + 1);
        auto inc = [&](int i) {
            for (++i; i <= n; i += i & -i) fw[i]++;
        };
        auto qry = [&](int i) {
            int s = 0;
            for (; i > 0; i -= i & -i) s += fw[i];
            return s;
        };
        long long res = 0;
        for (int i = n - 1; i >= 0; --i) {
            res += qry(p[i]);
            inc(p[i]);
        }
        return res;
    }
};
