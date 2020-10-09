// 1.cpp
class Solution {
public:
  int islandPerimeter(vector<vector<int>> &grid) {
    int row = grid.size();
    if (row == 0)
      return 0;
    int col = grid[0].size();
    int sum = 0;
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++)
        sum += check(i, j, grid);
    return sum;
  }
  int check(int i, int j, vector<vector<int>> &grid) {
    if (grid[i][j] == 0)
      return 0;
    int len = 4;
    if (i - 1 >= 0)
      if (grid[i - 1][j] == 1)
        len -= 2;
    if (j - 1 >= 0)
      if (grid[i][j - 1] == 1)
        len -= 2;
    return len;
  }
};
