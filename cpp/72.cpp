class Solution {
  // Runtime: 8 ms, faster than 96.76% of C++ online submissions for Edit
  // Distance. Memory Usage: 11.4 MB, less than 15.14% of C++ online submissions
  // for Edit Distance.
public:
  int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
      dp[i][0] = i;
    for (int j = 1; j <= n; j++)
      dp[0][j] = j;
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        dp[i][j] =
            word1[i - 1] == word2[j - 1]
                ? dp[i - 1][j - 1]
                : dp[i][j] =
                      min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
    return dp[m][n];
  }
};