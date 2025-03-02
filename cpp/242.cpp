// hash.cpp
class Solution {
public:
  bool isAnagram(string s, string t) {
    int count[26] = {};
    for (int i = 0; i < s.size(); ++i)
      ++count[s[i] - 'a'];
    for (int i = 0; i < t.size(); ++i)
      --count[t[i] - 'a'];
    for (int i = 0; i < 26; ++i)
      if (count[i] != 0)
        return 0;
    return 1;
  }
};
