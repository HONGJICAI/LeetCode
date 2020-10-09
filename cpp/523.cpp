// hashset.cpp
class Solution {
public:
  bool checkSubarraySum(vector<int> &nums, int k) {
    unordered_set<int> set;
    int len = nums.size(), sum = 0, pre = 0, i;
    for (i = 0; i < len; ++i) {
      sum += nums[i];
      int mod = k == 0 ? sum : sum % k;
      if (set.find(mod) != set.end())
        return 1;
      set.insert(pre);
      pre = mod;
    }
    return 0;
  }
};
