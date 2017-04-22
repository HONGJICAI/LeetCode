class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        for(int i=1;i<n;++i)
            s=iteration(s);
        return s;
    }
    string iteration(string s){
        int i=0,j=1,n=s.size();
        string ss="";
        for(;j<n;++j){
            if(s[i]!=s[j]){
                ss+=to_string(j-i)+s[i];
                i=j;
            }
        }
        ss+=to_string(j-i)+s[i];
        return ss;
    }
};
