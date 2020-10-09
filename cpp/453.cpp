// sort.cpp
class Solution {
public:
  int minMoves(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int count = 0;
    for (int i = 1; i < nums.size(); i++) {
      count += nums[i] - nums[0];
    }
    return count;
  }
};
