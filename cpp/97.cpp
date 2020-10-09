// dp.cpp
class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
    if (n1 + n2 != n3)
      return 0;
    vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= n1; ++i)
      for (int j = 0; j <= n2; ++j)
        if (i > 0 && dp[i - 1][j])
          dp[i][j] = s3[i + j - 1] == s1[i - 1];
        else if (j > 0 && dp[i][j - 1] && dp[i][j] != 1)
          dp[i][j] = s3[i + j - 1] == s2[j - 1];
    return dp[n1][n2];
  }
};
// TLE_dfs.cpp
class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size())
      return 0;
    return dfs(s1, s2, s3, 0, 0, 0);
  }
  bool dfs(string &s1, string &s2, string &s3, int i, int j, int k) {
    if (i == s1.size() && j == s2.size())
      return true;
    bool res = 0;
    if (i < s1.size() && s1[i] == s3[k])
      res |= dfs(s1, s2, s3, i + 1, j, k + 1);
    if (j < s2.size() && s2[j] == s3[k])
      res |= dfs(s1, s2, s3, i, j + 1, k + 1);
    return res;
  }
};
