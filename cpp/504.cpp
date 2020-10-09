// base7.cpp
class Solution {
public:
  string convertToBase7(int num) {
    if (num == 0)
      return "0";
    bool neg = 0;
    if (num < 0) {
      neg = 1;
      num = -num;
    }
    char ch;
    string s = "";
    while (num > 0) {
      ch = num % 7 + '0';
      s = ch + s;
      num = (num - num % 7) / 7;
    }
    if (neg == 1)
      s = '-' + s;
    return s;
  }
};
