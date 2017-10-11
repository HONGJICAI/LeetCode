class Solution {
    bool helper(string &s,int i,string &p,int j){
        while(i<s.size()&&j<p.size()){
            switch(p[j]){
                case '?':i++,j++;break;
                case '*':{
                    ++j;
                    for(int k=1;i+k<=s.size();++k)
                        if(helper(s,i+k,p,j))
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
public:
    bool isMatch(string s, string p) {
        return helper(s,0,p,0);
    }
};
