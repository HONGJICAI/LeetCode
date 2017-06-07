class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int i=n/2;i>0;--i)
            if(n%i==0){
                string str;
                for(int j=0;j<n/i;++j)
                    str+=s.substr(0,i);
                if(str==s)
                    return 1;
            }
        return 0;
    }
};
