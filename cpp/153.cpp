class Solution {
  // Runtime: 4 ms, faster than 89.79% of C++ online submissions for Find
  // Minimum in Rotated Sorted Array. Memory Usage: 8.8 MB, less than 29.27% of
  // C++ online submissions for Find Minimum in Rotated Sorted Array.
public:
  int findMin(vector<int> &nums) {
    int minVal = 0x7fffffff;
    function<void(int, int)> helper = [&](int low, int high) {
      if (low > high)
        return;
      if (nums[low] <= nums[high])
        minVal = min(minVal, nums[low]);
      else {
        int mid = (high + low) / 2;
        helper(low, mid - 1);
        helper(mid + 1, high);
        minVal = min(minVal, nums[mid]);
      }
    };
    helper(0, nums.size() - 1);
    return minVal;
  }
};