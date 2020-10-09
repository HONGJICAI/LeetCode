class Solution { // write at 2017, 15ms
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] >= target)
        high = mid;
      else
        low = mid + 1;
    }
    if (nums.size() == 0 || nums[low] != target)
      return vector<int>(2, -1);
    vector<int> res(2, low);
    high = nums.size() - 1;
    while (low < high) {
      int mid = low + (high - low) / 2 + 1;
      if (nums[mid] <= target)
        low = mid;
      else
        high = mid - 1;
    }
    res[1] = high;
    return res;
  }
};
class Solution { // Runtime: 8 ms, faster than 97.20% of C++ online submissions
                 // for Find First and Last Position of Element in Sorted Array.
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    auto l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    return l == nums.size() || nums[l] != target
               ? vector<int>{-1, -1}
               : vector<int>{l, upper_bound(nums.begin(), nums.end(), target) -
                                    nums.begin() - 1};
  }
};