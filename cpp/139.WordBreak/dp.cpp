class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size()==0)return false;
        unordered_set<string>hashset(wordDict.begin(),wordDict.end());
        vector<int>dp(s.size()+1,0);
        dp[0]=1;
        for(int i=1;i<=s.size();++i)
            for(int j=i-1;j>=0;--j)
                if(dp[j]&&hashset.find( s.substr(j,i-j) )!=hashset.end()){
                    dp[i]=true;
                    break;
                }
        return dp[s.size()];
    }
};
