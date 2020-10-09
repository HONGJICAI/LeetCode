// xor-13ms.cpp
class Solution {
public:
  vector<int> singleNumber(vector<int> &nums) {
    vector<int> result(2);
    int sum = 0, len = nums.size(), off = 0, temp;
    for (int i = 0; i < len; ++i)
      sum ^= nums[i];
    for (temp = sum; (temp & 1) != 1; ++off, temp >>= 1)
      ;
    temp = sum;
    for (int i = 0; i < len; ++i)
      if (nums[i] & (1 << off))
        temp ^= nums[i];
    result[0] = temp;
    result[1] = sum ^ temp;
    return result;
  }
};
