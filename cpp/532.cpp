// onepass-39ms.cpp
class Solution {
public:
  int findPairs(vector<int> &nums, int k) {
    set<pair<int, int>> s;
    sort(nums.begin(), nums.end());
    int i = 0, j = 1, diff, len = nums.size();
    for (; j < len && i < len;) {
      diff = nums[j] - nums[i];
      if (diff == k) {
        s.insert(make_pair(nums[i], nums[j]));
        ++j;
        ++i;
      } else if (diff < k)
        ++j;
      else
        ++i;
      if (i == j)
        ++j;
    }
    return s.size();
  }
};
