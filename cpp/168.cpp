// onepass-0ms.cpp
class Solution {
public:
  string convertToTitle(int n) {
    string str = "";
    while (n > 0) {
      char ch = ((n - 1) % 26 + 'A');
      str = ch + str;
      n = (n - 1) / 26;
    }
    return str;
  }
};
