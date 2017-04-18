class Solution {
public:
    bool checkRecord(string s) {
        int a=0,l=0,n=s.size(),maxl=0;
        for(int i=0;i<n;++i)
            if(s[i]=='A'||s[i]=='a'){
                ++a;
                l=0;
            }
            else if(s[i]=='L'||s[i]=='l'){
                ++l;
                maxl=l>maxl?l:maxl;
            }
            else
                l=0;
        return a<=1&&maxl<=2;
    }
};
