// hash.cpp
class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int number = 0, sum = 0, n = nums.size();
    unordered_map<int, int> map;
    map[0] = 1;
    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      number += map[sum - k];
      ++map[sum];
    }
    return number;
  }
};
