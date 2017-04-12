class Solution {
public:
    int longestPalindrome(string s) {
        int a[58]={};
        int len=s.size();
        for(int i=0;i<len;++i)
            ++a[s[i]-'A'];
        int result=0;
        bool flag=0;
        for(int i=0;i<58;++i)
            if(a[i]>0){
                if(a[i]%2==0){
                    result+=a[i];
                    a[i]=0;
                }
                else{
                    result+=a[i]-1;
                    a[i]=1;
                    flag=1;
                }
            }
        if(flag==1)
            return result+1;
        return result;
    }
};
