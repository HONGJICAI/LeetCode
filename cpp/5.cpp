// center-extend.cpp
class Solution {
  int getPalindromeLength(string &str, int index) {
    int len = 1;
    while (index - len >= 0 && index + len < str.size() &&
           str[index - len] == str[index + len])
      ++len;
    return len - 1;
  } //#b#a#b#a#d#,#c#b#b#d#
public:
  string longestPalindrome(string s) {
    if (s.size() <= 1)
      return s;
    string str = "#";
    for (int i = 0; i < s.size(); ++i, str += "#")
      str.append(1, s[i]);
    int len = 0, cur, index;
    for (int i = 1; i < str.size(); ++i) {
      cur = getPalindromeLength(str, i);
      if (cur > len) {
        len = cur;
        index = i;
      }
    }
    return s.substr(index / 2 - len / 2, len);
  }
};
