// onepass-3ms.cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0, len = nums.size();
        for (; j < len; ++j)
            if (nums[j] != val)
                nums[i++] = nums[j];
        return i;
    }
};
