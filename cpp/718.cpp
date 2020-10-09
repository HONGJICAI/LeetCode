class Solution {
  // Runtime: 188 ms
  // Memory Usage: 106.4 MB
public:
  int findLength(vector<int> &A, vector<int> &B) {
    int m = A.size(), n = B.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    int maxlen = 0;
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++) {
        if (A[i - 1] == B[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          maxlen = max(maxlen, dp[i][j]);
        }
      }
    return maxlen;
  }
};
// found an interesting solution
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/solution/
// named 'Binary Search with Rolling Hash'