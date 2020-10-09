// onepass-179ms.cpp
class NumArray {
  vector<int> dp;

public:
  NumArray(vector<int> nums) {
    int len = nums.size();
    if (len == 0)
      return;
    dp.assign(len, nums[0]);
    for (int i = 1; i < len; ++i)
      dp[i] = dp[i - 1] + nums[i];
  }

  int sumRange(int i, int j) {
    if (i > j) {
      int temp = i;
      i = j;
      j = temp;
    }
    if (i == 0)
      return dp[j];
    return dp[j] - dp[i - 1];
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
