class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size()==0) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int i1 = g.size()-1;
        int i2 = s.size()-1;
        while(i1>=0 && i2 >=0){
            if(g[i1] <= s[i2]){
                i1--;
                i2--;
                count++;
            }
            else i1--;
        }
        return count;
    }
};
