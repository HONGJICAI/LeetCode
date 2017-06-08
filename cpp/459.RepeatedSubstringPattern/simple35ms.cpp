class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int i=n/2;i>0;--i)
            if(n%i==0&&isRepeated(s,i))
                return 1;
        return 0;
    }
    bool isRepeated(string&s,int len){
        for(int i=len;i<s.size();)
            for(int j=0;j<len;++j,++i)
                if(s[j]!=s[i])
                    return 0;
        return 1;
    }
};
