// easyMath.cpp
class Solution {
public:
  int numberOfArithmeticSlices(vector<int> &A) {
    int n = A.size() - 1;
    if (n < 2)
      return 0;
    for (int i = 0; i < n; ++i)
      A[i] = A[i + 1] - A[i];
    int count = 0, res = 0;
    for (int i = 1; i < n; ++i)
      if (A[i] == A[i - 1])
        ++count;
      else {
        res += (1 + count) * count / 2;
        count = 0;
      }
    res += (1 + count) * count / 2;
    return res;
  }
};
