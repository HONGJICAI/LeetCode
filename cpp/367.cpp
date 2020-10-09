// 1-0ms.cpp
class Solution {
public:
  bool isPerfectSquare(int num) {
    if (num == 0)
      return 0;
    int i = 1;
    while (num > 0) {
      num -= i;
      i += 2;
    }
    return num == 0;
  }
};
// 2-0ms.cpp
class Solution {
public:
  bool isPerfectSquare(int num) {
    int i = 1, j = num;
    while (i <= j) {
      long long mid = (i + j) >> 1;
      if (mid * mid == num)
        return 1;
      else if (mid * mid > num)
        j = mid - 1;
      else
        i = mid + 1;
    }
    return 0;
  }
};
