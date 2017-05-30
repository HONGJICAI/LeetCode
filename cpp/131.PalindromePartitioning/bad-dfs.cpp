class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>r;
        dfs(res,r,"",s);
        return res;
    }
    void dfs(vector<vector<string>>&res,vector<string>&r,string pre,string last){
        if(pre!=""&&isPalindrome(pre)){
            r.push_back(pre);
            dfs(res,r,"",last);
            r.pop_back();
        }
        if(last==""){
            if(pre=="")
                res.push_back(r);
            return;
        }
        dfs(res,r,pre+last[0],last.substr(1));
    }
    bool isPalindrome(string &s){
        int i=0,j=s.size()-1;
        while(i<j)
            if(s[i++]!=s[j--])
                return 0;
        return 1;
    }
};
