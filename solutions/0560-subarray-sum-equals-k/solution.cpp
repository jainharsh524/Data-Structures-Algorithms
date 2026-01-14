class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;   // base case: empty prefix

        int sum = 0;
        int count = 0;

        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            // If sum - k has appeared before, those form valid subarrays
            if(mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }

            // Store current prefix sum
            mp[sum]++;
        }

        return count;
    }
};

