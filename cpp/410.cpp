class Solution {
  // Runtime: 4 ms
  // Memory Usage: 8.6 MB
public:
  int splitArray(vector<int> &nums, int m) {
    long long left = 0, right = 0;
    for (auto num : nums) {
      left = max(left, (long long)num);
      right += num;
    }
    while (left < right) {
      auto mid = left + (right - left) / 2;
      if ([](const vector<int> &nums, int cuts, long long max) {
            long long acc = 0;
            for (auto num : nums) {
              if (acc + num <= max)
                acc += num;
              else {
                --cuts;
                acc = num;
                if (cuts < 0)
                  return false;
              }
            }
            return true;
          }(nums, m - 1, mid))
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  }
};