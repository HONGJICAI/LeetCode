// simplehash+dfs+9ms.cpp
class Solution {
  unordered_set<int> ver, lTilt, rTilt;
  vector<vector<string>> res;
  vector<string> r;
  int n;

public:
  vector<vector<string>> solveNQueens(int n) {
    string str(n, '.');
    this->n = n;
    r.assign(n, str);
    dfs(0);
    return res;
  }
  void dfs(int i) {
    if (i == n) {
      res.push_back(r);
      return;
    }
    for (int j = 0; j < n; ++j)
      if (ver.find(j) == ver.end() && lTilt.find(i - j) == lTilt.end() &&
          rTilt.find(i + j) == rTilt.end()) {
        ver.insert(j), lTilt.insert(i - j), rTilt.insert(i + j);
        r[i][j] = 'Q';
        dfs(i + 1);
        r[i][j] = '.';
        ver.erase(j), lTilt.erase(i - j), rTilt.erase(i + j);
      }
  }
};
// smarthash+dfs+3ms.cpp
class Solution {
  vector<int> flag;
  vector<vector<string>> res;
  vector<string> r;
  int n;

public:
  vector<vector<string>> solveNQueens(int n) {
    string str(n, '.');
    this->n = n;
    r.assign(n, str);
    flag.assign(5 * n, 1);
    dfs(0);
    return res;
  }
  void dfs(int i) {
    if (i == n) {
      res.push_back(r);
      return;
    }
    for (int j = 0; j < n; ++j)
      if (flag[j] && flag[n + i + j] && flag[4 * n + i - j]) {
        flag[j] = flag[n + i + j] = flag[4 * n + i - j] = 0;
        r[i][j] = 'Q';
        dfs(i + 1);
        r[i][j] = '.';
        flag[j] = flag[n + i + j] = flag[4 * n + i - j] = 1;
      }
  }
};