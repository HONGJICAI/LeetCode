// BinarySearch-0ms.cpp
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int i = 1, j = n, mid;
    while (j <= j) {
      mid = i + (j - i) / 2;
      if (isBadVersion(mid))
        if (!isBadVersion(mid - 1))
          return mid;
        else
          j = mid - 1;
      else
        i = mid + 1;
    }
    return mid;
  }
};
