// dp.cpp
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int row = obstacleGrid.size();
    if (row == 0)
      return 0;
    int col = obstacleGrid[0].size();
    if (col == 0)
      return 1;
    vector<vector<int>> res(row, vector<int>(col, 0));
    res[0][0] = !obstacleGrid[0][0];
    for (int i = 0; i < row; ++i)
      for (int j = 0; j < col; ++j)
        if (obstacleGrid[i][j] != 1) {
          res[i][j] += i > 0 ? res[i - 1][j] : 0;
          res[i][j] += j > 0 ? res[i][j - 1] : 0;
        }
    return res[row - 1][col - 1];
  }
};
