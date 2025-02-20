// onepass-3ms.cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
      int l = 0, r = s.size() - 1;
      while (r >= 0 && s[r] == ' ') --r;
      while (r >= 0 && s[r] != ' ') {
        ++l;
        --r;
      }
      return l;
    }
};
