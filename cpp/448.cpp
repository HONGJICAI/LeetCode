// TimeOnSpaceO1.cpp
class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    int len = nums.size();
    int value;
    for (int i = 0; i < len; i++) {
      if ((value = abs(nums[i])) > 0) {
        nums[value - 1] < 0 ? nums[value - 1] = nums[value - 1]
                            : nums[value - 1] = -nums[value - 1];
      }
    }
    vector<int> disappear;
    for (int i = 0; i < nums.size(); i++)
      if (nums[i] > 0)
        disappear.push_back(i + 1);
    return disappear;
  }
};
