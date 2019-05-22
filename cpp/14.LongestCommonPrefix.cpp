class Solution { // 4ms
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0||strs[0].size()==0)
            return "";
        string pre="";
        for(int j=0;j<strs[0].size();++j){
            char ch=strs[0][j];
            for(int i=1;i<strs.size();++i){
                if(strs[i].size()<=j||strs[i][j]!=ch)
                    return pre;
            }
            pre+=ch;
        }
        return pre;
    }
};