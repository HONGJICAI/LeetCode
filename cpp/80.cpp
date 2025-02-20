class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, l = 1;
        for (bool twice = false; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                if (twice)
                    continue;
                twice = true;
            } else {
                twice = false;
            }
            nums[l++] = nums[i];
        }
        return l;
    }
};