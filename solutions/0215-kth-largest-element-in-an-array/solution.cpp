class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for( int ele: nums){
            pq.push(ele);
        }
        int temp;
        for(int i = 0;i<k;i++){
            temp = pq.top();
            pq.pop();
        }
        return temp;
    }
};
