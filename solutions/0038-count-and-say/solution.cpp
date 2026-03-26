class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        string nres = "";
        for(int i = 1;i<n;i++){
            int count = 0;
            char ele = res[0];
            int sz = res.size();
            for(int i = 0;i<sz;i++){
                if(res[i]==ele){
                    count++;
                }
                else{
                    string ap = to_string(count)+res[i-1];
                    nres.append(ap);
                    count = 1;
                    ele = res[i];
                }
            }
            string ap = to_string(count)+ele;
            nres.append(ap);
            res = nres;
            nres = "";
        }
        return res;
    }
};
