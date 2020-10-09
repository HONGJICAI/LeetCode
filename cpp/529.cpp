// simple.cpp
class Solution {
  enum { GAME_OVER, CLICK_SUCCESS };
  int height, width, n;

public:
  vector<vector<char>> updateBoard(vector<vector<char>> &board,
                                   vector<int> &click) {
    height = board.size(), width = board[0].size(), n = click.size();
    for (int i = 0; i < n; i += 2)
      if (onClick(board, click[i], click[i + 1]) == GAME_OVER)
        return board;
    return board;
  }
  int onClick(vector<vector<char>> &board, int x, int y) {
    switch (board[x][y]) {
    case 'M': {
      board[x][y] = 'X';
      return GAME_OVER;
    }
    case 'E': {
      int count = 0;
      for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j)
          if (x + i < 0 || y + j < 0 || x + i >= height || y + j >= width)
            continue;
          else if (board[x + i][y + j] == 'M')
            ++count;
      if (count == 0) {
        board[x][y] = 'B';
        for (int i = -1; i <= 1; ++i)
          for (int j = -1; j <= 1; ++j)
            if (x + i < 0 || y + j < 0 || x + i >= height || y + j >= width)
              continue;
            else
              onClick(board, x + i, y + j);
      } else
        board[x][y] = '0' + count;
    }
    }
    return CLICK_SUCCESS;
  }
};
