// xor-13ms.cpp
class Solution {
  public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (auto n : nums)
            result ^= n;
        return result;
    }
};
