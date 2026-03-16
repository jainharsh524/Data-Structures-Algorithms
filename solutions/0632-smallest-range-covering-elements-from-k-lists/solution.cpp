class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int k = nums.size();

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        int currentMax = INT_MIN;

        // push first element of each list
        for(int i = 0; i < k; i++) {
            pq.push({nums[i][0], i, 0});
            currentMax = max(currentMax, nums[i][0]);
        }

        int rangeStart = 0;
        int rangeEnd = INT_MAX;

        while(true) {

            auto [value, listId, index] = pq.top();
            pq.pop();

            if(currentMax - value < rangeEnd - rangeStart) {
                rangeStart = value;
                rangeEnd = currentMax;
            }

            if(index + 1 == nums[listId].size())
                break;

            int nextVal = nums[listId][index + 1];

            pq.push({nextVal, listId, index + 1});

            currentMax = max(currentMax, nextVal);
        }

        return {rangeStart, rangeEnd};
    }
};
