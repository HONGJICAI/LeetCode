class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(),n2=s2.size(),n3=s3.size();
        if(n1+n2!=n3)
            return 0;
        vector<vector<bool>>dp(n1+1,vector<bool>(n2+1,0));
        dp[0][0]=1;
        for(int i=0;i<=n1;++i)
            for(int j=0;j<=n2;++j)
                if(i>0&&dp[i-1][j])
                    dp[i][j]=s3[i+j-1]==s1[i-1];
                else if(j>0&&dp[i][j-1]&&dp[i][j]!=1)
                    dp[i][j]=s3[i+j-1]==s2[j-1];
        return dp[n1][n2];
    }
};
