class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1)
            return s;
        string res;
        string *arr=new string[numRows];
        for(int i=0,j=0,sign=1;i<s.size();++i){
            arr[j]+=s[i];
            if(j==numRows-1)
                sign=-1;
            else if(j==0)
                sign=1;
            j+=sign;
        }
        for(int i=0;i<numRows;++i)
            res+=arr[i];
        return res;
    }
};
