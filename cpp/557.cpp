// onepass.cpp
class Solution {
public:
  string reverseWords(string s) {
    int i = 0, j = 0, n = s.size();
    while (j < n) {
      if (s[j] == ' ') {
        reverse(s, i, j - 1);
        i = j + 1;
      }
      ++j;
    }
    reverse(s, i, j - 1);
    return s;
  }
  void reverse(string &s, int i, int j) {
    while (i < j)
      swap(s[i++], s[j--]);
  }
};
