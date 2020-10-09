// onepass.cpp
class Solution {
public:
  string reverseStr(string s, int k) {
    int len = s.size();
    for (int i = 0; i < len; i += 2 * k)
      if (i + k < len)
        reverse(s, i, i + k - 1);
      else
        reverse(s, i, len - 1);
    return s;
  }
  void reverse(string &s, int i, int j) {
    while (i < j) {
      char temp = s[i];
      s[i++] = s[j];
      s[j--] = temp;
    }
  }
};
