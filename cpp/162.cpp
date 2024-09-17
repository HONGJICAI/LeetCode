class Solution {
  public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size();
        while (l < r) {
            int m = (l + r) / 2;
            bool condition1 = m == 0 || nums[m] > nums[m - 1];
            bool condition2 = m == nums.size() - 1 || nums[m] > nums[m + 1];
            if (condition1 && condition2)
                return m;
            if (!condition1)
                r = m;
            else
                l = m + 1;
        }
        return -1;
    }
};