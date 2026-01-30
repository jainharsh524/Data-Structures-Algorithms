class Solution {
private:
    template <class It, class V, class L>
    static It find(It beg, const It end, const V &k, const L cmp) __attribute__((always_inline)) {
        if (beg == end) {
            return beg;
        } else if (beg + 8u > end) {
            while (beg < end && cmp(*beg, k)) beg++;
            return beg;
        } else {
            return lower_bound(beg, end, k, cmp);
        }
    }

public:
    static vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newint) {
        const auto beg = intervals.begin(), end = intervals.end();
        const auto its = find(beg, end, newint[0], [](const vector<int> &v, const int k) __attribute__((always_inline)) {
            return v[1] < k;
        });
        const auto ite = find(its, end, newint[1] + 1, [](const vector<int> &v, const int k) __attribute__((always_inline)) {
            return v[0] < k;
        });
        if (its != ite) {
            (*its)[0] = min((*its)[0], newint[0]);
            (*its)[1] = max((ite[-1])[1], newint[1]);
            intervals.erase(its + 1u, ite);
        } else {
            intervals.insert(its, move(newint));
        }
        return move(intervals);
    }
};
