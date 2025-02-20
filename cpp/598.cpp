// simple.cpp
class Solution {
public:
  int maxCount(int m, int n, vector<vector<int>> &ops) {
    if (ops.size() == 0)
      return m * n;
    int a = 0x7fffffff, b = 0x7fffffff;
    for (auto nums : ops) {
      a = min(nums[0], a);
      b = min(nums[1], b);
    }
    return a * b;
  }
};
