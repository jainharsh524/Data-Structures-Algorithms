class MedianFinder {
public:
    priority_queue<int> maxhp; //elements smaller than median
    priority_queue<int,
            vector<int>, 
            greater<int>> minhp; // elements greater than median
    MedianFinder() {
        
    }
    void addNum(int num) {
        maxhp.push(num);
        minhp.push(maxhp.top());
        maxhp.pop();
        if(minhp.size() > maxhp.size()){
            maxhp.push(minhp.top());
            minhp.pop();
        }
    }
    double findMedian() {
        if(maxhp.size() > minhp.size()) return maxhp.top();
        return (maxhp.top() + minhp.top())/2.0;  
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
