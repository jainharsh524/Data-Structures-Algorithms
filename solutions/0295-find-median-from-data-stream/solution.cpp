class MedianFinder {
public:
    multiset<int> mini;
    multiset<int> maxi;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!maxi.empty()&&*maxi.begin()<num){
            maxi.insert(num);
        }
        else mini.insert(num);
        adjust();
    }
    
    void adjust(){
        if(abs((int)mini.size()-(int)maxi.size())>1){
            if(mini.size()>maxi.size()){
                auto it = mini.end();
                it--;
                maxi.insert(*it);
                mini.erase(it);
            }
            else{
                mini.insert(*maxi.begin());
                auto it = maxi.find(*maxi.begin());
                maxi.erase(it);
            }
        }
    }

    double findMedian() {
        if(mini.size()==maxi.size()){
            int a = *maxi.begin();
            int b = *prev(mini.end());
            return (double)a+((double)(b-a))/2;
        }
        else{
            // double m = -1;
            if(mini.size()>maxi.size()){
                double m = *prev(mini.end())*1.0;
                return m;
            }
            else{
                double m = *maxi.begin()*1.0;
                return m;
            }
            // return m;
        }
    }

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
