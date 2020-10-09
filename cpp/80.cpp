// hash-12ms.cpp
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return 0;
    int times = 1, value = nums[0];
    int count = 1;
    for (int i = 1; i < n; ++i) {
      if (times == 2 && value == nums[i])
        continue;
      if (value == nums[i])
        ++times;
      else {
        times = 1;
        value = nums[i];
      }
      nums[count++] = nums[i];
    }
    return count;
  }
};
