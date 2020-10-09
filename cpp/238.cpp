// notbest-75ms.cpp
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> pre(n, nums[0]);
    vector<int> last(n, nums[n - 1]);
    for (int i = 1; i < n; ++i)
      pre[i] = nums[i] * pre[i - 1];
    for (int i = n - 2; i >= 0; --i)
      last[i] = nums[i] * last[i + 1];
    vector<int> result(n);
    for (int i = 1; i < n - 1; ++i)
      result[i] = pre[i - 1] * last[i + 1];
    result[0] = last[1];
    result[n - 1] = pre[n - 2];
    return result;
  }
};
