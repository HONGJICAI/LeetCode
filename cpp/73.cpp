// inplace.cpp
class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int row = matrix.size();
    if (row == 0)
      return;
    int col = matrix[0].size();
    bool allZero = matrix[0][0] == 0, rowZero = 0, colZero = 0;
    for (int i = 0; i < row; ++i)
      for (int j = 0; j < col; ++j)
        if (matrix[i][j] == 0) {
          rowZero = i == 0 ? true : rowZero;
          colZero = j == 0 ? true : colZero;
          matrix[i][0] = matrix[0][j] = 0;
        }
    for (int i = 1; i < row; ++i)
      for (int j = 1; j < col; ++j)
        if (matrix[0][j] == 0 || matrix[i][0] == 0)
          matrix[i][j] = 0;
    if (allZero)
      colZero = rowZero = 1;
    if (rowZero)
      matrix[0] = vector<int>(col, 0);
    if (colZero)
      for (int i = 0; i < row; ++i)
        matrix[i][0] = 0;
  }
};
