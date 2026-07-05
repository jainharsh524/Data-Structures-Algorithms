class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0;
        int r = 0;
        int maxlen = 0;
        unordered_map<int, int> mp;
        for(r = 0;r<fruits.size();r++){
            mp[fruits[r]]++;
            maxlen = max(maxlen, r-l);
            while(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++;
            }
        }
        maxlen = max(maxlen, r-l);
        return maxlen;
    }
};
