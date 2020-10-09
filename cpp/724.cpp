// doubleScan.cpp
class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    nums.push_back(0);
    int n = nums.size() - 1, i = 0,
        right = accumulate(nums.begin() + 1, nums.end(), 0), left = 0;
    while (i < n && left != right) {
      left += nums[i++];
      right -= nums[i];
    }
    return left == right && i < n ? i : -1;
  }
};
