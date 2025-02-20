// simple.cpp
class Solution {
public:
  int dominantIndex(vector<int> &nums) {
    auto it = max_element(begin(nums), end(nums));
    if (it == nums.end())
      return -1;
    for (auto num : nums)
      if (2 * num > *it && num != *it)
        return -1;
    return distance(nums.begin(), it);
  }
};
