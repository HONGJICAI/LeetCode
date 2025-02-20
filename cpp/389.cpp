// hash-3ms.cpp
class Solution {
public:
  char findTheDifference(string s, string t) {
    int *a = new int[26]();
    int *b = new int[26]();
    for (int i = 0; i < s.size(); ++i)
      ++a[s[i] - 'a'];
    for (int i = 0; i < t.size(); ++i)
      ++b[t[i] - 'a'];
    for (int i = 0; i < 26; ++i)
      if (a[i] != b[i])
        return 'a' + i;
  }
};
