// onepass-0ms.cpp
class Solution {
public:
  int countSegments(string s) {
    int n = s.size();
    int count = 0;
    bool word = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == ' ')
        word = 0;
      else {
        if (word == 0)
          ++count;
        word = 1;
      }
    }
    return count;
  }
};
