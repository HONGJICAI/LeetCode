// singleScan.cpp
class Solution {
public:
  bool checkPossibility(vector<int> &nums) {
    if (nums.size() <= 2)
      return true;
    int count = 0, left = 0, right = nums.size() - 1;
    while (left < right && nums[left] <= nums[left + 1])
      ++left;
    while (left < right && nums[right] >= nums[right - 1])
      --right;
    if (left == right)
      return true;
    if (nums[left] > nums[right] && right - left == 1)
      return (left == 0 || nums[left - 1] <= nums[right]) ||
             (right == nums.size() - 1 || nums[left] <= nums[right + 1]);
    return false;
  }
};
