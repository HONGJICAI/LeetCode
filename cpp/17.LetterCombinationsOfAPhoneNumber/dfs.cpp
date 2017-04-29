class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>letter={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>res;
        if(digits.size()==0)return res;
        dfs(letter,res,digits,"",0);
        return res;
    }
    void dfs(vector<string>&letter,vector<string>&res,const string &digits,string cur,int i){
        if(i==digits.size()){
            res.push_back(cur);
            return;
        }
        for(int j=0;j<letter[digits[i]-'0'].size();++j)
            dfs(letter,res,digits,cur+letter[digits[i]-'0'][j],i+1);
    }
};
