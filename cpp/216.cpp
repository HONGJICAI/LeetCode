// dfs.cpp
class Solution {
  vector<vector<int>> result;
  int targetK;
  int targetN;

public:
  vector<vector<int>> combinationSum3(int k, int n) {
    targetK = k;
    if (n > 45 || n <= 0)
      return result;
    targetN = n;
    dfs(0, 1, 0, vector<int>());
    return result;
  }
  void dfs(int k, int n, int sum, vector<int> num) {
    if (sum == targetN && k == targetK) {
      result.push_back(num);
      return;
    }
    if (k == targetK || n >= 10 || sum >= targetN)
      return;
    dfs(k, n + 1, sum, num);
    num.push_back(n);
    dfs(k + 1, n + 1, sum + n, num);
  }
};
