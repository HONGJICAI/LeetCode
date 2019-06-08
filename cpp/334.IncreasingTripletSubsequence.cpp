class Solution {
//Runtime: 8 ms, faster than 87.77% of C++ online submissions for Increasing Triplet Subsequence.
//Memory Usage: 9.2 MB, less than 45.15% of C++ online submissions for Increasing Triplet Subsequence.
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1 = INT_MAX, c2 = INT_MAX;
        for (int x : nums)
            if (x <= c1)
                c1 = x;
            else if (x <= c2)
                c2 = x;
            else
                return true;
        return false;
    }
};