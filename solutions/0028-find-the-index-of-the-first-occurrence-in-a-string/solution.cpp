class Solution {
public:
    bool check(string haystack, string needle, int index1, int index2){
        for(int i = index1;i<=index2;i++){
            if(haystack[i]!=needle[i-index1]) return false;
        }
        return true;
    }
    int strStr(string haystack, string needle) {
        if(haystack.size()<needle.size()) return -1;
        int i = 0;
        int j = i+needle.size()-1;
        int index = -1;
        while(j<haystack.size()){
            if(haystack[i]!=needle[0]){
                i++;j++;
            }
            else{
                if(check(haystack, needle, i, j)){
                    index = i;
                    break;
                }
                else{
                    i++;j++;
                }
            }
        }
        return index;
    }
};
