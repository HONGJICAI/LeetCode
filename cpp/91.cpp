// DP.cpp
class Solution {
public:
  int numDecodings(string s) {
    if (s.empty() || (s.size() >= 1 && s[0] == '0'))
      return 0;
    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;
    for (int i = 1; i < dp.size(); i++) {
      dp[i] += (s[i - 1] == '0') ? 0 : dp[i - 1];
      if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')))
        dp[i] += dp[i - 2];
    }
    return dp.back();
  }
};
// inverseDP.cpp
class Solution {
public:
  int numDecodings(string s) {
    int n = s.size();
    if (n == 0)
      return 0;
    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    dp[n - 1] = s[n - 1] == '0' ? 0 : 1;
    for (int i = n - 2; i >= 0; --i) {
      if (s[i] == '0')
        continue;
      if (stoi(s.substr(i, 2)) <= 26) {
        dp[i] += dp[i + 2];
      }
      dp[i] += dp[i + 1];
    }
    return dp[0];
  }
};
