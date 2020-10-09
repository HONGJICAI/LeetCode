// singleScan.cpp
class Solution {
public:
  bool validPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r)
      if (s[l++] != s[r--])
        return isPalindromic(s, l - 1, r) || isPalindromic(s, l, r + 1);
    return true;
  }
  bool isPalindromic(string &s, int l, int r) {
    while (l < r)
      if (s[l++] != s[r--])
        return false;
    return true;
  }
};
