// dp.cpp
class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    vector<int> dp(cost.size() + 1, 0);
    dp[0] = cost[0];
    dp[1] = cost[1];
    cost.push_back(0);
    for (int i = 2; i < dp.size(); ++i)
      dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    cost.pop_back();
    return dp.back();
  }
};
