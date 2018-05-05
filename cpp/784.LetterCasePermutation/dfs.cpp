class Solution {
    void dfs(vector<string>&res,string &s,int i){
        if(i==s.size()){
            res.push_back(s);
            return;
        }
        dfs(res,s,i+1);
        if(s[i]>='a'&&s[i]<='z'){
            s[i]+=-'a'+'A';
            dfs(res,s,i+1);
        }
        else if(s[i]>='A'&&s[i]<='Z'){
            s[i]+=-'A'+'a';
            dfs(res,s,i+1);
        }   
    }
public:
    vector<string> letterCasePermutation(string S) {
        vector<string>res;
        dfs(res,S,0);
        return res;
    }
};
