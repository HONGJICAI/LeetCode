// onepass.cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = nums.size() - 1;
        for (int j = last - 1; j >= 0; j--)
            if (nums[j] + j >= last)
                last = j;
        return last == 0;
    }
};
