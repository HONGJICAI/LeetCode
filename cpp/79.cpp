// dfs.cpp
class Solution {
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k,
             vector<vector<bool>>& visited) {
        if (k == word.size()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] != word[k] || visited[i][j])
            return false;
        visited[i][j] = 1;
        if (dfs(board, word, i + 1, j, k + 1, visited) ||
            dfs(board, word, i, j + 1, k + 1, visited) ||
            dfs(board, word, i - 1, j, k + 1, visited) ||
            dfs(board, word, i, j - 1, k + 1, visited))
            return true;
        visited[i][j] = 0;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        if (row == 0 || word.size() == 0)
            return 0;
        int col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, 0));
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (board[i][j] == word[0] &&
                    dfs(board, word, i, j, 0, visited))
                    return true;
        return false;
    }
};
