// recursion.cpp
class Solution {
public:
  int integerBreak(int n) {
    switch (n) {
    case 2:
      return 1;
    case 3:
      return 2;
    }
    return helper(n);
  }
  int helper(int n) {
    if (n <= 2)
      return n;
    if (n % 3 == 0)
      return pow(3, n / 3);
    return 2 * helper(n - 2);
  }
};
