class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)return "";
        if(strs[0].size()==0)return "";
        string pre="";
        bool over=0;
        for(int j=0;;++j){
            char ch=strs[0][j];
            for(int i=1;i<strs.size();++i){
                if(strs[i].size()<=j)
                    return pre;
                if(strs[i][j]!=ch){
                    over=1;
                    break;
                }
            }
            if(over==1||strs[0].size()<=j)break;
            pre+=strs[0][j];
        }
        return pre;
    }
};
