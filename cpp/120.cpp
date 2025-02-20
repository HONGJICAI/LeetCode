// dp.cpp
class Solution {
  public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<vector<int>> dp{triangle[0]};
        for (int i = 0; i < row - 1; ++i) {
            dp.push_back(vector<int>(triangle[i + 1].size(), 0x7fffffff));
            for (int j = 0; j < triangle[i].size(); ++j) {
                for (int x = 0; x <= 1; ++x)
                    if (j + x >= 0 && j + x < triangle[i + 1].size())
                        dp[i + 1][j + x] =
                            min(dp[i + 1][j + x],
                                triangle[i + 1][j + x] + dp[i][j]);
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};
