// dfs.cpp
class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    dfs(res, "", 0, 0, n);
    return res;
  }
  void dfs(vector<string> &res, string cur, int left, int right, int n) {
    if (right > left || left > n)
      return;
    if (left + right == n * 2) {
      res.push_back(cur);
      return;
    }
    dfs(res, cur + "(", left + 1, right, n);
    dfs(res, cur + ")", left, right + 1, n);
  }
};
