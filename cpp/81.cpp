// confuse.cpp
class Solution {
public:
  bool search(vector<int> &nums, int target) {
    if (nums.size() == 0)
      return 0;
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid] == target)
        return 1;
      if (nums[l] == nums[mid] && nums[mid] == nums[r])
        ++l, --r;
      else if (nums[mid] >= nums[l]) {
        if (nums[l] <= target && target < nums[mid])
          r = mid - 1;
        else
          l = mid + 1;
      } else if (nums[mid] <= nums[r]) {
        if (nums[mid] < target && target <= nums[r])
          l = mid + 1;
        else
          r = mid - 1;
      }
    }
    return false;
  }
};
