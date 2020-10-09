// smart-146ms.cpp
class Solution {
public:
  vector<int> findDuplicates(vector<int> &nums) {
    int len = nums.size();
    vector<int> result;
    for (int i = 0; i < len; ++i) {
      if (nums[abs(nums[i]) - 1] < 0)
        result.push_back(abs(nums[i]));
      else
        nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
    }
    return result;
  }
};
