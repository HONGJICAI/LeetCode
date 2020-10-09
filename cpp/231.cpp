// bits-feature-3ms.cpp
class Solution {
public:
  bool isPowerOfTwo(int n) { return !(n & (n - 1)) && (n > 0); }
};
