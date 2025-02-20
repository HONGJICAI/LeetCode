// bfs.cpp
class Solution {
    int row, col, row2, col2;
    void bfs(vector<vector<char>>& board, char origin, char target, int i,
             int j) {
        vector<pair<int, int>> st = {{i, j}};
        while (!st.empty()) {
            auto [i, j] = st.back();
            st.pop_back();
            if (i < 0 || j < 0 || i >= row || j >= col || board[i][j] != origin)
                continue;
            board[i][j] = target;
            st.push_back({i + 1, j});
            st.push_back({i - 1, j});
            st.push_back({i, j + 1});
            st.push_back({i, j - 1});
        }
    }

  public:
    void solve(vector<vector<char>>& board) {
        row = board.size(), row2 = row - 1;
        if (row == 0)
            return;
        col = board[0].size(), col2 = col - 1;
        for (int i = 0; i < col; ++i) {
            if (board[0][i] == 'O')
                bfs(board, 'O', 'a', 0, i);
            if (board[row - 1][i] == 'O')
                bfs(board, 'O', 'a', row - 1, i);
        }
        for (int i = 1; i < row - 1; ++i) {
            if (board[i][0] == 'O')
                bfs(board, 'O', 'a', i, 0);
            if (board[i][col - 1] == 'O')
                bfs(board, 'O', 'a', i, col - 1);
        }

        for (int i = 1; i < row2; ++i)
            for (int j = 1; j < col2; ++j)
                if (board[i][j] == 'O')
                    board[i][j] = 'X';

        for (int i = 0; i < col; ++i) {
            if (board[0][i] == 'a')
                bfs(board, 'a', 'O', 0, i);
            if (board[row - 1][i] == 'a')
                bfs(board, 'a', 'O', row - 1, i);
        }
        for (int i = 1; i < row - 1; ++i) {
            if (board[i][0] == 'a')
                bfs(board, 'a', 'O', i, 0);
            if (board[i][col - 1] == 'a')
                bfs(board, 'a', 'O', i, col - 1);
        }
    }
};
