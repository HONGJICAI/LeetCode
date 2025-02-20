// simple.cpp
class Solution {
  int getCount(string &s, int l, int r, char lval) {
    int len = 1;
    while (l - len >= 0 && r + len < s.size() && s[l - len] == lval &&
           s[r + len] != lval)
      len++;
    return len;
  }

public:
  int countBinarySubstrings(string s) {
    int res = 0;
    for (int i = 1; i < s.size(); ++i)
      if (s[i - 1] != s[i])
        res += getCount(s, i - 1, i, s[i - 1]);
    return res;
  }
};
// singleScan.cpp
class Solution2 {
public:
  int countBinarySubstrings(string s) {
    int pre = 0, cur = 1, res = 0;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == s[i - 1])
        ++cur;
      else {
        pre = cur;
        cur = 1;
      }
      if (cur <= pre)
        ++res;
    }
    return res;
  }
};
