class Solution {
  // Runtime: 44 ms, faster than 12.45% of C++ online submissions for Remove K
  // Digits. Memory Usage: 180 MB, less than 8.63% of C++ online submissions for
  // Remove K Digits.
public:
  string removeKdigits(string num, int k) {
    if (k >= num.size())
      return "0";
    if (k == 0) {
      int i = 0;
      while (i < num.size() and num[i] == '0')
        ++i;
      return i == num.size() ? "0" : num.substr(i);
    }
    for (int i = 0; i + 1 < num.size(); ++i)
      if (num[i] > num[i + 1])
        return removeKdigits(num.substr(0, i) + num.substr(i + 1), k - 1);
    return removeKdigits(num.substr(0, num.size() - k), 0);
  }
};