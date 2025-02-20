// O32.cpp
class Solution {
public:
  int getSum(unsigned int a, unsigned int b) {
    if (a == 0 || b == 0)
      return a | b;
    int sum = 0, c = 0;
    for (int i = 0; (a != 0 || b != 0 || c != 0) && i < 32;
         ++i, a >>= 1, b >>= 1) {
      int aa = a & 1, bb = b & 1;
      if ((aa ^ bb ^ c) == 1) // 1 or 3 one
        sum = sum | (1 << i);
      if ((aa == 1 && bb == 1) || (aa == 1 && c == 1) ||
          (bb == 1 && c == 1)) // 2 or 3 one
        c = 1;
      else
        c = 0;
    }
    return sum;
  }
};
