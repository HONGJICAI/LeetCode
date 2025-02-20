class Solution {
  // Runtime: 12 ms, faster than 97.03% of C++ online submissions for Majority
  // Element II. Memory Usage: 10.5 MB, less than 85.68% of C++ online
  // submissions for Majority Element II.
public:
  vector<int> majorityElement(vector<int> &nums) {
    int count1 = 0, count2 = 0;
    int result1 = 0, result2 = 1;
    for (int num : nums) {
      if (num == result1)
        count1++;
      else if (num == result2)
        count2++;
      else if (count1 == 0) {
        result1 = num;
        count1 = 1;
      } else if (count2 == 0) {
        result2 = num;
        count2 = 1;
      } else {
        count1--;
        count2--;
      }
    }
    count1 = count2 = 0;
    for (int num : nums) {
      if (num == result1)
        count1++;
      else if (num == result2)
        count2++;
    }
    vector<int> ret;
    if (count1 > nums.size() / 3)
      ret.push_back(result1);
    if (count2 > nums.size() / 3)
      ret.push_back(result2);
    return ret;
  }
};