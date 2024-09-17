// dp-16ms.cpp
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int len = nums.size();
    vector<int> dp(len);
    dp[0] = nums[0];
    for (int i = 1; i < len; ++i)
      dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    int MAX = dp[0];
    for (int i = 1; i < len; ++i)
      MAX = max(dp[i], MAX);
    return MAX;
  }
};
class SolutionNoSpace {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        for (int sum = 0, l = 0; l < nums.size(); ++l) {
            sum += nums[l];
            ret = max(sum, ret);
            if (sum < 0){
                sum = 0;
            }
        }
        return ret;
    }
};