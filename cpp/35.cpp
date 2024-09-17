class Solution { // 8ms
public:
  int searchInsert(vector<int> &nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] == target)
        return m;
      else if (nums[m] < target)
        l = m + 1;
      else
        r = m;
    }
    return l;
  }
};
class Solution2 {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return it == nums.end() ? nums.size() : it - nums.begin();
    }
};