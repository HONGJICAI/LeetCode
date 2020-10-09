// binary-search.cpp
class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    return helper(0, nums.size() - 1, nums);
  }
  int helper(int left, int right, vector<int> &nums) {
    if (left == right)
      return nums[left];
    int mid = (left + right) / 2;
    if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
      return nums[mid];
    if (((right - left) / 2) & 1) { // odd
      if (nums[mid] == nums[mid + 1])
        return helper(left, mid - 1, nums);
      else if (nums[mid] == nums[mid - 1])
        return helper(mid + 1, right, nums);
    } else { // even
      if (nums[mid] == nums[mid + 1])
        return helper(mid + 2, right, nums);
      else if (nums[mid] == nums[mid - 1])
        return helper(left, mid - 2, nums);
    }
  }
};
// single-scan.cpp
class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i += 2)
      if (i == nums.size() - 1 || nums[i] != nums[i + 1])
        return nums[i];
  }
};
