// onepass.cpp
class Solution {
  public:
    int majorityElement(vector<int>& nums) {
        int last = nums[0], count = 1;
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] == last)
                ++count;
            else {
                if (--count == 0) {
                    last = nums[i];
                    count = 1;
                }
            }
        return last;
    }
};