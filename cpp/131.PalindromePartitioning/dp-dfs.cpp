class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        int n=s.size();
        if(n==0) return ret;
        vector<string> path;
        vector<vector<bool>>dp(n,vector<bool>(n,0));
        for(int i=0;i<n;++i)
            for(int j=0;j<=i;++j)
                dp[j][i]=s[i]==s[j]&&(i-j<=2||dp[j+1][i-1]);
        dfs(0, s, path, ret,dp);
        return ret;
    }
    void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret,vector<vector<bool>>&dp) {
        if(index == s.size()) {
            ret.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i) 
            if(dp[index][i]) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(i+1, s, path, ret,dp);
                path.pop_back();
            }
    }
};
