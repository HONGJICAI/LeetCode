// dfs.cpp
class Solution {
  int row, col, row2, col2;

public:
  void solve(vector<vector<char>> &board) {
    row = board.size(), row2 = row - 1;
    if (row == 0)
      return;
    col = board[0].size(), col2 = col - 1;
    for (int i = 0; i < col; ++i) {
      if (board[0][i] == 'O')
        dfs(board, 'O', 'a', 0, i);
      if (board[row - 1][i] == 'O')
        dfs(board, 'O', 'a', row - 1, i);
    }
    for (int i = 1; i < row; ++i) {
      if (board[i][0] == 'O')
        dfs(board, 'O', 'a', i, 0);
      if (board[i][col - 1] == 'O')
        dfs(board, 'O', 'a', i, col - 1);
    }

    for (int i = 1; i < row2; ++i)
      for (int j = 1; j < col2; ++j)
        if (board[i][j] == 'O')
          board[i][j] = 'X';

    for (int i = 0; i < col; ++i) {
      if (board[0][i] == 'a')
        dfs(board, 'a', 'O', 0, i);
      if (board[row - 1][i] == 'a')
        dfs(board, 'a', 'O', row - 1, i);
    }
    for (int i = 1; i < row; ++i) {
      if (board[i][0] == 'a')
        dfs(board, 'a', 'O', i, 0);
      if (board[i][col - 1] == 'a')
        dfs(board, 'a', 'O', i, col - 1);
    }
  }
  void dfs(vector<vector<char>> &board, char origin, char target, int i,
           int j) {
    stack<pair<int, int>> st;
    st.push(make_pair(i, j));
    while (!st.empty()) {
      i = st.top().first;
      j = st.top().second;
      st.pop();
      if (i < 0 || j < 0 || i >= row || j >= col || board[i][j] != origin)
        continue;
      board[i][j] = target;
      st.push(make_pair(i + 1, j));
      st.push(make_pair(i - 1, j));
      st.push(make_pair(i, j + 1));
      st.push(make_pair(i, j - 1));
    }
  }
};
