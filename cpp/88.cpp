class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m + n - 1;
        --m, --n;
        while (n >= 0 && m >= 0)
            nums1[last--] = nums1[m] <= nums2[n] ? nums2[n--] : nums1[m--];
        while (n >= 0)
            nums1[last--] = nums2[n--];
    }
};
