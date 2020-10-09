// bruteForce.cpp
class Solution {
public:
  int strStr(string haystack, string needle) {
    for (int i = 0; i <= (int)haystack.size() - (int)needle.size(); ++i)
      for (int j = 0;; ++j) {
        if (j == needle.size())
          return i;
        if (needle[j] != haystack[i + j])
          break;
      }
    return -1;
  }
};
