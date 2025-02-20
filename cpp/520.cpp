// onepass-9ms.cpp
class Solution {
public:
  bool detectCapitalUse(string word) {
    if (word.size() == 1)
      return 1;
    int ch = word[0] - 'a';
    if (ch >= 0) {
      for (int i = 1; i < word.size(); ++i)
        if (word[i] < 'a')
          return 0;
      return 1;
    }
    ch = word[1] - 'a';
    if (ch >= 0) {
      for (int i = 1; i < word.size(); ++i)
        if (word[i] < 'a')
          return 0;
    } else {
      for (int i = 1; i < word.size(); ++i)
        if (word[i] >= 'a')
          return 0;
    }
    return 1;
  }
};
