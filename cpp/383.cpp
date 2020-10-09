// hash-25ms.cpp
class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    int a[58] = {}, b[58] = {};
    for (int i = 0; i < ransomNote.size(); ++i)
      ++a[ransomNote[i] - 'A'];
    for (int i = 0; i < magazine.size(); ++i)
      ++b[magazine[i] - 'A'];
    for (int i = 0; i < 58; ++i)
      if (a[i] > b[i])
        return 0;
    return 1;
  }
};
