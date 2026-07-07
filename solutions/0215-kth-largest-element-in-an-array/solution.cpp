class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int ele: nums) pq.push(ele);
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};
