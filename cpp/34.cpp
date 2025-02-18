class Solution {
  int lower_bound(vector<int>& nums, int target) {
      int left = 0, right = nums.size();
      while (left < right) {
          int mid = left + (right - left) / 2;
          if (nums[mid] < target) {
              left = mid + 1;
          } else {
              right = mid;
          }
      }
      return left;
  }
  int upper_bound(vector<int>& nums, int target) {
      int left = 0, right = nums.size();
      while (left < right) {
          int mid = left + (right - left) / 2;
          if (nums[mid] <= target) {
              left = mid + 1;
          } else {
              right = mid;
          }
      }
      return left;
  }

public:
  vector<int> searchRange(vector<int>& nums, int target) {
      int left = lower_bound(nums, target);
      if (left == nums.size() || nums[left] != target)
          return {-1, -1};
      return {left, upper_bound(nums, target) - 1};
  }
};