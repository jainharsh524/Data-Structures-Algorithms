class Solution {
public:
    vector<int> firstIndexMatch(string a, char ch){
        vector<int> res;
        for(int i = 0;i<a.size();i++){
            if(a[i]==ch) res.push_back(i);
        }
        return res;
    }
    int repeatedStringMatch(string a, string b) {
        vector<int> index = firstIndexMatch(a, b[0]);
        int mincnt = INT_MAX;
        for(int j: index){
            int cnt = 1;
            bool flag = true;
            for(int i = 0;i<b.size();i++){
                if(j==a.size()){
                    j = j%(a.size());
                    cnt++;
                }
                if(a[j]!=b[i]){
                    flag = false;
                    break;
                }
                else j++;
            }
            if(flag)mincnt = min(cnt, mincnt);
        }
        return mincnt==INT_MAX ? -1 : mincnt;
    }
};
