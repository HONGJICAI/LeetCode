// onepass-6ms.cpp
class Solution {
public:
  int titleToNumber(string s) {
    int j = s.size(), sum = 0;
    for (int i = 0; i < j; ++i) {
      sum = sum * 26 + (s[i] - 'A') % 26 + 1;
    }
    return sum;
  }
};
