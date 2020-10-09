class Solution {
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for House
  // Robber II. Memory Usage: 8.6 MB, less than 52.00% of C++ online submissions
  // for House Robber II.
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n < 2)
      return n ? nums[0] : 0;
    auto robber = [&nums](int l, int r) {
      int take = 0, notake = 0;
      for (int i = l; i <= r; i++) {
        int notake_temp = notake;
        notake = max(take, notake);
        take = max(notake_temp + nums[i], take);
      }
      return max(take, notake);
    };
    return max(robber(0, n - 2), robber(1, n - 1));
  }
};