// better29ms.cpp
class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    int n = s.size();
    if (n <= 1)
      return false;
    vector<int> factors(1, 1);
    for (int i = 2; i * i <= n; ++i)
      if (n % i == 0) {
        factors.push_back(i);
        factors.push_back(n / i);
      }
    for (auto it : factors)
      if (isRepeated(s, it))
        return 1;
    return 0;
  }
  bool isRepeated(string &s, int len) {
    for (int i = len; i < s.size();)
      for (int j = 0; j < len; ++j, ++i)
        if (s[j] != s[i])
          return 0;
    return 1;
  }
};
// simple35ms.cpp
class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    int n = s.size();
    for (int i = n / 2; i > 0; --i)
      if (n % i == 0 && isRepeated(s, i))
        return 1;
    return 0;
  }
  bool isRepeated(string &s, int len) {
    for (int i = len; i < s.size();)
      for (int j = 0; j < len; ++j, ++i)
        if (s[j] != s[i])
          return 0;
    return 1;
  }
};
