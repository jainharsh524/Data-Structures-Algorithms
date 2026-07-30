class Solution {
public:
    int minimumPushes(string word) {
        int cnt = 0;
        int sz = word.size();
        int pushes = 1;

        while(sz > 0){
            int take = min(8, sz);
            cnt += take * pushes;
            sz -= take;
            pushes++;
        }

        return cnt;
    }
};
