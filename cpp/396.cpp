class Solution {
  // Runtime: 8 ms, faster than 96.67% of C++ online submissions for Rotate
  // Function. Memory Usage: 9.7 MB, less than 14.48% of C++ online submissions
  // for Rotate Function.
public:
  int maxRotateFunction(vector<int> &A) {
    auto sum = 0ll;
    for (auto num : A)
      sum += num;
    auto f0 = 0ll;
    for (auto i = 0ll; i < A.size(); ++i)
      f0 += i * A[i];
    auto ret = f0;
    for (int i = 1; i < A.size(); ++i)
      ret = max(ret, f0 = f0 + sum - (long long)A.size() * A[A.size() - i]);
    return ret;
  }
};