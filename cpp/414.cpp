// On.cpp
class Solution {
public:
  int thirdMax(vector<int> &nums) {
    long long min = LLONG_MIN;
    long long max1 = nums[0], max2 = min, max3 = min, len = nums.size();
    for (int i = 1; i < len; i++) {
      if (nums[i] == max1 || nums[i] == max2)
        continue;
      if (nums[i] > max1) {
        max3 = max2;
        max2 = max1;
        max1 = nums[i];
      } else if (nums[i] > max2) {
        max3 = max2;
        max2 = nums[i];
      } else if (nums[i] > max3) {
        max3 = nums[i];
      }
    }
    if (min == max3)
      return max1;
    else
      return max3;
  }
};
