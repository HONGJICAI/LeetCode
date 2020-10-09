// O32n.cpp
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int res = 0, n = nums.size();
    for (int i = 0; i < 32; ++i) {
      int count = 0, mask = 1 << i;
      for (int j = 0; j < n; ++j)
        if (nums[j] & mask)
          ++count;
      if (count % 3 != 0)
        res |= mask;
    }
    return res;
  }
};
