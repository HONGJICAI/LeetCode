// noExtraSpace.cpp
class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size(), times = n / 2;
    for (int k = 0; k < times; ++k)
      for (int i = k; i < n - k - 1; ++i) {
        int temp = matrix[k][i];
        matrix[k][i] = matrix[n - 1 - i][k];
        matrix[n - 1 - i][k] = matrix[n - 1 - k][n - 1 - i];
        matrix[n - 1 - k][n - 1 - i] = matrix[i][n - 1 - k];
        matrix[i][n - 1 - k] = temp;
      }
  }
};
class Solution2 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int level = 0; level < matrix.size() / 2; ++ level) {
            for (int i = 0; level + i < n - 1 - level; ++i) {
                auto &lt = matrix[level][level + i];
                auto &rt = matrix[level + i][n - level - 1];
                auto &lb = matrix[n - level - 1 - i][level];
                auto &rb = matrix[n - level - 1][n - level - 1 - i];
                auto temp = lt;
                lt = lb;
                lb = rb;
                rb = rt;
                rt = temp;
            }
        }
    }
};