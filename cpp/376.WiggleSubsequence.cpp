class Solution {
//Runtime: 4 ms, faster than 86.10% of C++ online submissions for Wiggle Subsequence.
//Memory Usage: 8.8 MB, less than 7.24% of C++ online submissions for Wiggle Subsequence.
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int up = 1, down = 1;
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] > nums[i-1])
                up = down + 1;
            else if (nums[i] < nums[i-1])
                down = up + 1;
        return max(up, down);
    }
};