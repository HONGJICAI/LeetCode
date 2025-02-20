// center-extend-3ms.cpp
class Solution {
public:
  int count = 0;
  int countSubstrings(string s) {
    for (int i = 0; i < s.size(); i++) {
      extendPalindrom(s, i, i);
      extendPalindrom(s, i, i + 1);
    }
    return count;
  }
  void extendPalindrom(string &s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      count++;
      left--, right++;
    }
  }
};
// dp-22ms.cpp
class Solution2 {
public:
  int countSubstrings(string s) {
    int n = s.size(), res = n;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
      dp[i][i] = 1;
    for (int len = 1; len < n; ++len)
      for (int i = 0; i + len < n; ++i)
        if (s[i] == s[i + len] && (dp[i + 1][i + len - 1] || len < 2))
          res += (dp[i][i + len] = 1);
    return res;
  }
};
