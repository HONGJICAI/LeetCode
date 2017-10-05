class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0,j=0;
        while(i<s.size()&&j<p.size()){
            switch(p[j]){
                case '?':i++,j++;break;
                case '*':{
                    ++j;
                    for(int k=s.size()-i;k>0;--k)
                        if(isMatch(s.substr(i+k),p.substr(j)))
                            return true;
                    break;
                 }
                default:{
                    if(s[i++]!=p[j++])
                        return false;
                }
            }
        }
        return i==s.size()&&(j==p.size()||p.find_first_not_of("*",j)==string::npos);
    }
};
