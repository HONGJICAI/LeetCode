// dfs-TLE.cpp
class Solution {
  int row, col;
  bool search(string &word, int index, vector<vector<char>> &board, int i,
              int j, vector<vector<int>> &visited) {
    if (i < 0 || i >= row || j < 0 || j >= col || visited[i][j] ||
        word[index] != board[i][j])
      return false;
    visited[i][j] = true;
    if (index == word.size() - 1) {
      visited[i][j] = false;
      return true;
    }
    if (search(word, index + 1, board, i + 1, j, visited) ||
        search(word, index + 1, board, i - 1, j, visited) ||
        search(word, index + 1, board, i, j + 1, visited) ||
        search(word, index + 1, board, i, j - 1, visited)) {
      visited[i][j] = false;
      return true;
    }
    visited[i][j] = false;
    return false;
  }

public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    unordered_map<char, vector<pair<int, int>>> position;
    row = board.size();
    vector<string> res;
    unordered_set<string> _words(words.begin(), words.end());
    if (row == 0)
      return res;
    col = board[0].size();
    for (int i = 0; i < row; ++i)
      for (int j = 0; j < col; ++j)
        position[board[i][j]].push_back(pair<int, int>(i, j));
    vector<vector<int>> visited(row, vector<int>(col, 0));
    for (auto word : _words)
      for (auto p : position[word[0]])
        if (search(word, 0, board, p.first, p.second, visited)) {
          res.emplace_back(word);
          break;
        }
    return res;
  }
};
