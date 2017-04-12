class Solution {
public:
    string reverseString(string s) {
        int len=s.size();
        if(len==0)return s;
        char temp;
        for(int i=0;i<len/2;i++){
            temp=s[i];
            s[i]=s[len-1-i];
            s[len-1-i]=temp;
        }
        return s;
    }
};
