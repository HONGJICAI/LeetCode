// onepass-9ms.cpp
class Solution {
public:
  string reverseVowels(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
      if (!isVowels(s[i]))
        ++i;
      if (!isVowels(s[j]))
        --j;
      if (isVowels(s[i]) && isVowels(s[j])) {
        char temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        ++i;
        --j;
      }
    }
    return s;
  }
  bool isVowels(char ch) {
    if (ch >= 'A' && ch <= 'Z')
      ch = ch - 'A' + 'a';
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
  }
};
