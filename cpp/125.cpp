// onepass-12ms.cpp
class Solution {
public:
  bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
      while (i < j && !isalphanumeric(s[i]))
        ++i;
      while (j >= i && !isalphanumeric(s[j]))
        --j;
      if (i >= j)
        return 1;
      if ((s[i] == s[j] || s[i] - 'a' + 'A' == s[j] ||
           s[i] - 'A' + 'a' == s[j]) &&
          isalphanumeric(s[i]) == isalphanumeric(s[j])) {
        ++i;
        --j;
      } else
        return 0;
    }
    return 1;
  }
  int isalphanumeric(char ch) {
    if (ch >= '0' && ch <= '9')
      return 1;
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
      return 2;
    return 0;
  }
};
