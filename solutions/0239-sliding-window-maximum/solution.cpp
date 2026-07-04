class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq; // stores INDICES

        for (int i = 0; i < nums.size(); i++) {

            // remove out-of-window indices
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            // maintain decreasing order
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);

            // window formed
            if (i >= k - 1)
                res.push_back(nums[dq.front()]);
        }

        return res;
    }
};

