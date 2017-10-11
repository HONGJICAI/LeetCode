class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0,j=0,star=-1,ii;
        while(i<s.size()){
            bool pNotOver=j<p.size();
            if(pNotOver&&(p[j]=='?'||s[i]==p[j])){
                i++,j++;
            }
            else if(pNotOver&&p[j]=='*'){
                star=++j;
                ii=i;
            }
            else if(star!=-1){
                j=star;
                i=++ii;
            }
            else
                return false;
        }
        return j==p.size()||p.find_first_not_of("*",j)==string::npos;
    }
};
