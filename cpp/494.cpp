// dp.cpp
class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int S) {
    int sum = 0, len = nums.size();
    for (int i = 0; i < len; ++i)
      sum += nums[i];
    if (((S + sum) & 1) == 1 || (sum + S) < 0 || sum < S)
      return 0;
    int V = (sum + S) >> 1;
    vector<int> dp(V + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < len; ++i)
      for (int v = V; nums[i] <= v; --v)
        dp[v] += dp[v - nums[i]];
    return dp[V];
  }
};
