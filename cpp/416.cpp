// 1-13ms.cpp
class Solution {
public:
  bool canPartition(vector<int> &nums) {
    bitset<10001> bits(1);
    int sum = 0, n = nums.size();
    for (auto i : nums) {
      sum += i;
      bits |= bits << i;
    }
    if ((sum & 1) == 1)
      return 0;
    return bits[sum / 2];
  }
};
// 2-29ms.cpp
class Solution2 {
public:
  bool canPartition(vector<int> &nums) {
    int sum = 0, n = nums.size();
    for (auto i : nums)
      sum += i;
    if ((sum & 1) == 1)
      return 0;
    sum /= 2;
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
      for (int j = sum; j >= nums[i]; --j)
        dp[j] = dp[j] || dp[j - nums[i]];
    return dp[sum];
  }
};