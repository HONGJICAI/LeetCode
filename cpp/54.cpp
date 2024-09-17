// iteration-3ms.cpp
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> result;
    int m = matrix.size();
    if (m < 1)
      return result;
    int n = matrix[0].size();
    int i = 0, j = 0;
    while (n > 0 && m > 0) {
      result.push_back(matrix[i][j]);
      int k = 1;
      --n;
      while (k <= n) {
        result.push_back(matrix[i][j + k]);
        ++k;
      }
      j = j + n;
      k = 1;
      --m;
      if (m == 0)
        break;
      while (k <= m) {
        result.push_back(matrix[i + k][j]);
        ++k;
      }
      i = i + m;
      k = 1;
      if (n == 0)
        break;
      while (k <= n) {
        result.push_back(matrix[i][j - k]);
        ++k;
      }
      j = j - n;
      k = 1;
      --m;
      while (k <= m) {
        result.push_back(matrix[i - k][j]);
        ++k;
      }
      i = i - m;
      j += 1;
      --n;
    }
    return result;
  }
};
class SolutionGenSteps {
    vector<int> genSteps(int m, int n) {
        if (m == 1)
            return {n-1, 0, 0, 0};
        if (n == 1)
            return {0, m - 1, 0, 0};
        return {n - 1, m - 1, n - 1, m - 2};
    }
public:
    vector<int> spiralOrder(vector<vector<int>> matrix) {
        auto directions = vector<pair<int, int>>{pair{0, 1}, pair{1, 0}, pair{0, -1}, pair{-1, 0}};
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0, j = 0, d = 0; res.size() < m * n; ++j) {
            res.push_back(matrix[i][j]);
            for (auto step: genSteps(m - 2 * i, n - 2 * i)) {
                auto [x, y] = directions[d];
                for (int k = 0; k < step; ++k) {
                    i += x, j += y;
                    res.push_back(matrix[i][j]);
                }
                d = (d + 1) % 4;
            }
        }
        return res;
    }
};