class Solution {
  public:
    int minCut(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= i; ++j)
                dp[j][i] = s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1]);
        if (dp[0][n - 1])
            return 0;
        vector<int> dp2(n, INT_MAX);
        for (int i = 0; i < n; ++i) {
            if (dp[0][i])
                dp2[i] = 0;
            else
                for (int j = 1; j <= i; ++j) {
                    if (dp[j][i])
                        dp2[i] = min(dp2[i], dp2[j - 1] + 1);
                }
        }
        return dp2[n - 1];
    }
};