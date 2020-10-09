// BinarySearch-0ms.cpp
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return
// 0
int guess(int num);

class Solution {
public:
  int guessNumber(int n) {
    int i = 1, j = n, mid;
    while (i <= j) {
      mid = i + (j - i) / 2;
      if (guess(mid) == -1)
        j = mid - 1;
      else if (guess(mid) == 1)
        i = mid + 1;
      else if (guess(mid) == 0)
        return mid;
    }
    return 0;
  }
};
