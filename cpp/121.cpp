// onepass
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int minPrice = prices[0], profit = 0;
        for (auto price : prices) {
            if (price < minPrice)
                minPrice = price;
            else
                profit = max(price - minPrice, profit);
        }
        return profit;
    }
};