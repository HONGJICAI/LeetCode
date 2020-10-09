// hashset+preprocess+dfs+3ms.cpp
class Solution {
  bool valid(int i, int j, char val, vector<vector<char>> &board) {
    for (int k = 0; k < 9; ++k)
      if (board[k][j] == val || board[i][k] == val)
        return false;
    int x = i / 3 * 3;
    int y = j / 3 * 3;
    for (i = x; i < x + 3; ++i)
      for (j = y; j < y + 3; ++j)
        if (board[i][j] == val)
          return false;
    return true;
  }
  void init(vector<vector<char>> &board, unordered_set<char> hashset[][9]) {
    for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j)
        if (board[i][j] != '.') {
          char ch = board[i][j];
          for (int k = 0; k < 9; ++k) {
            hashset[k][j].erase(ch);
            hashset[i][k].erase(ch);
          }
          int x = i / 3 * 3;
          int y = j / 3 * 3;
          for (int a = x; a < x + 3; ++a)
            for (int b = y; b < y + 3; ++b)
              hashset[a][b].erase(ch);
        }
  }
  bool dfs(int i, int j, vector<vector<char>> &board,
           unordered_set<char> hashset[][9]) {
    if (j == 9) {
      return i == 8 ? true : dfs(i + 1, 0, board, hashset);
    }
    if (hashset[i][j].size() == 0)
      return dfs(i, j + 1, board, hashset);
    else {
      for (auto it = hashset[i][j].begin(); it != hashset[i][j].end(); ++it) {
        if (valid(i, j, *it, board)) {
          board[i][j] = *it;
          if (dfs(i, j + 1, board, hashset))
            return true;
          board[i][j] = 0;
        }
      }
      return false;
    }
  }

public:
  void solveSudoku(vector<vector<char>> &board) {
    unordered_set<char> hashset[9][9];
    for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j)
        if (board[i][j] == '.')
          hashset[i][j] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    init(board, hashset);
    dfs(0, 0, board, hashset);
  }
};
