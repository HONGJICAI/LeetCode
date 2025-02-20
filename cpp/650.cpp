// simpleDP.cpp
class Solution {
public:
  int minSteps(int n) {
    if (n < 2)
      return 0;
    vector<int> dp(n + 1, 0);
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
      dp[i] = i;
      for (int j = i - 1; j >= 2; --j)
        if (i % j == 0)
          dp[i] = min(dp[j] + i / j, dp[i]);
    }
    return dp[n];
  }
};
// smart.cpp
class Solution2 {
public:
  int minSteps(int n) {
    if (n == 1)
      return 0;
    for (int i = 2; i < n; i++)
      if (n % i == 0)
        return i + minSteps(n / i);
    return n;
  }
};
