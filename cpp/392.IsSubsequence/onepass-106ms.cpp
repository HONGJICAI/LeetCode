class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0,slen=s.size(),tlen=t.size();
        for(;i<slen&&j<tlen;++j)
            if(s[i]==t[j])
                ++i;
        return i==slen;
    }
};
