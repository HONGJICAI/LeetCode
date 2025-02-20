// better.cpp
class Solution {
public:
  int totalHammingDistance(vector<int> &nums) {
    int res = 0;
    for (int i = 0; i < 32; ++i) {
      int bitCount = 0;
      for (int num : nums)
        bitCount += (num >> i) & 1;
      res += bitCount * (nums.size() - bitCount);
    }
    return res;
  }
};
// more-better.cpp
class Solution2 {
public:
  int totalHammingDistance(vector<int> &nums) {
    vector<int> stack(32);
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
      int tmp = nums[i];
      for (int j = 0; j < 32; j++) {
        stack[j] += tmp & 1;
        tmp = tmp >> 1;
      }
    }
    for (int i = 0; i < stack.size(); i++)
      res += stack[i] * (nums.size() - stack[i]);
    return res;
  }
};
// TLE.cpp
class Solution3 {
public:
  int totalHammingDistance(vector<int> &nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i)
      for (int j = i + 1; j < nums.size(); ++j)
        res += getHammingDistance(nums[i], nums[j]);
    return res;
  }
  int getHammingDistance(unsigned int num1, unsigned int num2) {
    int res = num1 ^ num2;
    res = ((res & 0xaaaaaaaa) >> 1) + (res & 0x55555555);
    res = ((res & 0xcccccccc) >> 2) + (res & 0x33333333);
    res = ((res & 0xf0f0f0f0) >> 4) + (res & 0x0f0f0f0f);
    res = ((res & 0xff00ff00) >> 8) + (res & 0x00ff00ff);
    res = ((res & 0xffff0000) >> 16) + (res & 0x0000ffff);
    return res;
  }
};
