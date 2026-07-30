class Solution {
public:
    string res;
    void CAS(int n, string& s){
        if(n==1){
            res = s;
            return;
        }
        string ns = "";
        int l = 0;
        int i = 0;
        for(i = 0;i<s.size();i++){
            if(s[l]!=s[i]){
                ns = ns+to_string(i-l)+s[l];
                l = i;
            }
        }
        ns = ns+to_string(i-l)+s[l];
        cout<<ns<<" "<<n<<endl;
        return CAS(n-1, ns);
    }
    string countAndSay(int n) {
        //"111221"->"312211"
        string s = "1";
        if(n==1) return s;
        CAS(n, s);
        return res;
    }
};
