// O32n.cpp
class Solution {
public:
  int findMaximumXOR(vector<int> &nums) {
    int maxVal = 0, mask = 0;
    for (int i = 31; i >= 0; i--) {
      mask |= 1 << i;
      unordered_set<int> hashset;
      for (auto num : nums)
        hashset.insert(num & mask);
      int target = maxVal | (1 << i);
      for (auto num : hashset)
        if (hashset.find(num ^ target) != hashset.end()) {
          maxVal = target;
          break;
        }
    }
    return maxVal;
  }
};
