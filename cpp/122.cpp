// onepass.cpp
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int profit = 0, n = prices.size();
    if (n == 0)
      return 0;
    int buy = prices[0];
    for (int i = 0; i < n; ++i)
      if (i + 1 == n || prices[i + 1] < prices[i]) {
        profit += prices[i] - buy;
        if (i + 1 < n)
          buy = prices[i + 1];
      }
    return profit;
  }
};
