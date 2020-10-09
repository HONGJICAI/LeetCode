// timeO243_spaceO9.cpp
class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    vector<int> nine(9, 0);
    for (int i = 0; i < 9; ++i) {
      nine.assign(9, 0);
      for (int j = 0; j < 9; ++j)
        if (board[i][j] != '.')
          if (nine[board[i][j] - '1']++ > 0)
            return 0;
    }
    for (int i = 0; i < 9; ++i) {
      nine.assign(9, 0);
      for (int j = 0; j < 9; ++j)
        if (board[j][i] != '.')
          if (nine[board[j][i] - '1']++ > 0)
            return 0;
    }
    for (int m = 0; m < 9; ++m) {
      nine.assign(9, 0);
      for (int i = m / 3 * 3; i < m / 3 * 3 + 3; ++i)
        for (int j = 3 * (m % 3); j < 3 * (m % 3) + 3; ++j)
          if (board[i][j] != '.')
            if (nine[board[i][j] - '1']++ > 0)
              return 0;
    }
    return 1;
  }
};
// timeO81_spaceO243.cpp
class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    int ver[9][9] = {0}, hor[9][9] = {0}, chunk[9][9] = {0}, num;
    for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j)
        if ((num = board[i][j]) != '.')
          if (ver[i][num - '1']++ > 0 || hor[j][num - '1']++ > 0 ||
              chunk[i / 3 * 3 + j / 3][num - '1']++ > 0)
            return 0;
    return 1;
  }
};
