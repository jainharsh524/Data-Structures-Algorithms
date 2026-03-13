class MedianStream{
    multiset<int> mins, maxs;
    public:
        void add(int num){
            if(!maxs.empty()&&num>= *maxs.begin()){
                maxs.insert(num);
            }
            else mins.insert(num);
            adjust(); //after each insertion both subtree should be balanced
        }
        void del(int num){
            auto it = mins.find(num);
            if(it!=mins.end()){
                mins.erase(it);
            }
            else{
                 auto it = maxs.find(num);
                if(it!=maxs.end()){
                    maxs.erase(it);
                }
            }
            adjust();
        }
        void adjust(){
            if(abs((int)maxs.size()-(int)mins.size())>1){
                if(maxs.size()>mins.size()){
                    mins.insert(*maxs.begin());
                    maxs.erase(maxs.begin());
                }
                else{
                    auto it= mins.end();
                    --it; //now it points to maximum element in mins
                    maxs.insert(*it);
                    mins.erase(it);
                }
            }
        }
        double median(){
            if(mins.size() == maxs.size()){
                double a = *mins.rbegin()*1.0;
                double b = *maxs.begin()*1.0;

            
                return (a+b)/2.0;
            }

            if(mins.size() >  maxs.size())
                return *mins.rbegin();
            
            else
                return *maxs.begin();
        };
};
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        MedianStream ms;

        for(int i = 0; i<nums.size();i++){
            
             if (i >= k) {
                 ms.del(nums[i - k]);
            }
            ms.add(nums[i]);
            if (i >= k - 1) {
                ans.push_back(ms.median());
            }
        }

        return ans;
        // priority_queue<int> pq;
        // int i = 0;
        // int j = 0;
        // vector<double> res;
        // while(j<nums.size()){
        //     pq.push(nums[j]);
        //     j++;
        //     if(pq.size()==k){
        //         priority_queue<int> rem;
        //         if((k&1) == 0){
        //             int j1 = 0;
        //             bool flag = false;
        //             while(j1<((k/2)-1)){
        //                 int ele = pq.top();
        //                 pq.pop();
        //                 j1++;
        //                 if(ele!=nums[i]||(flag&&(ele==nums[i]))) {
        //                     rem.push(ele);
        //                 }
        //                 else if(ele==nums[i]) flag = true;
        //             }
        //             int a = pq.top();pq.pop();
        //             if(a!=nums[i]||(flag&&(a==nums[i]))) {
        //                 rem.push(a);
        //             }
        //             else if(!flag&&(a==nums[i])) flag = true;
        //             int b = pq.top();pq.pop();
        //             if(b!=nums[i]||(flag&&(b==nums[i]))) {
        //                 rem.push(b);
        //             }
        //             else if(!flag&&(b==nums[i])) flag = true;
        //             res.push_back(a + (b - a) / 2.0);
        //             while(!pq.empty()){
        //                 int ele = pq.top();
        //                 pq.pop();
        //                 if(ele!=nums[i]||(flag&&(ele==nums[i]))) {
        //                     rem.push(ele);
        //                 }
        //                 else if(!flag&&(ele==nums[i])) flag = true;
        //             }
        //             cout<<a<<" "<<b<<" "<<i<<" "<<j<<" "<<endl;
        //             i++;
        //             priority_queue<int> temp;
        //             temp = rem;
        //             rem = pq;
        //             pq = temp;
        //         }
        //         else {
        //             int j1 = 0;
        //             bool flag = false;
        //             while(j1<(k/2)){
        //                 int ele = pq.top();
        //                 pq.pop();
        //                 j1++;
        //                 if(ele!=nums[i]||(flag&&(ele==nums[i]))) {
        //                     rem.push(ele);
        //                 }
        //                 else if(ele==nums[i]) flag = true;
        //             }
        //             int a = pq.top();pq.pop();
        //             if(a!=nums[i]||(flag&&(a==nums[i]))) {
        //                 rem.push(a);
        //             }
        //             else if(!flag&&(a==nums[i])) flag = true;
        //             res.push_back(a);
        //             cout<<a<<" "<<i<<" "<<j<<" "<<endl;
        //             while(!pq.empty()){
        //                 int ele = pq.top();
        //                 pq.pop();
        //                 if(ele!=nums[i]||(flag&&(ele==nums[i]))) {
        //                     rem.push(ele);
        //                 }
        //                 else if(!flag&&(ele==nums[i])) flag = true;
        //             }
        //             i++;
        //             swap(pq, rem);
        //             cout<<pq.size()<<endl;
        //         }
        //     }
        // }
        // return res;
    }
};
