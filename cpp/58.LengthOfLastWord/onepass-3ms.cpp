class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0,i=s.size()-1;
        while(i>=0&& !((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')))--i;
        while(i>=0){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
                ++len;
            else
                return len;
            --i;
        }
        return len;
    }
};
