// findkthlarge.cpp
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    if (((n1 + n2) & 1) == 0)
      return (findKthBig(nums1, n1, nums2, n2, (n1 + n2) / 2) +
              findKthBig(nums1, n1, nums2, n2, (n1 + n2) / 2 + 1)) /
             2.0;
    return findKthBig(nums1, n1, nums2, n2, (n1 + n2) / 2 + 1);
  }
  int findKthBig(vector<int> &nums1, int end1, vector<int> &nums2, int end2,
                 int k) {
    if (end1 > end2)
      return findKthBig(nums2, end2, nums1, end1, k);
    if (end1 == 0)
      return nums2[end2 - k];
    if (k == 1)
      return max(nums1[end1 - 1], nums2[end2 - 1]);
    int p = min(k / 2, end1);
    if (nums1[end1 - p] > nums2[end2 - p])
      return findKthBig(nums1, end1 - p, nums2, end2, k - p);
    return findKthBig(nums1, end1, nums2, end2 - p, k - p);
  }
};
