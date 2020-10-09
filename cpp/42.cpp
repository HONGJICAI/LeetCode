// onepass.cpp
class Solution {
public:
  int trap(vector<int> &height) {
    int low = 0, high = height.size() - 1, sum = 0;
    while (low < high) {
      while (low < high && height[low] < height[low + 1])
        low++;
      while (low < high && height[high] < height[high - 1])
        high--;
      int v1 = height[low], v2 = height[high];
      if (v1 < v2)
        while (low < high && v1 >= height[low])
          sum += v1 - height[low++];
      else
        while (low < high && v2 >= height[high])
          sum += v2 - height[high--];
    }
    return sum;
  }
};
