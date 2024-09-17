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
// binary search, remove half of the elements in vector each time
class SolutionCpp20 {
    int findNth(span<int> nums, int n){
        return nums[n - 1];
    }
    int findNth(span<int> nums1, span<int> nums2, int n){
        if (nums1.size() == 0) return findNth(nums2, n);
        if (nums2.size() == 0) return findNth(nums1, n);
        if (n == 1) return min(nums1[0], nums2[0]);
        int xval = nums1[nums1.size() / 2], yval = nums2[nums2.size() / 2];
        if (xval <= yval) {
            int xlcnt = nums1.size() / 2 + 1, ylcnt = nums2.size() / 2 + 1;
            if (xlcnt + ylcnt <= n) {
                return findNth(nums1.subspan(xlcnt), nums2, n - xlcnt);
            } else {
                return findNth(nums1, nums2.subspan(0, ylcnt - 1), n);
            }
        } else {
            return findNth(nums2, nums1, n);
        }
    }
public:
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
        int c = nums1.size() + nums2.size();
        if (c == 0) return 0;
        if(!(c & 1)){
            return (findNth(nums1, nums2, c / 2 + 1) + findNth(nums1, nums2, c / 2)) / 2.0;
        }else{
            return findNth(nums1, nums2, c / 2 + 1);
        }
    }
};
// binary search, remove n/2 elements in vector each time
class SolutionCpp20 {
    int findNth(span<int> nums, int n){
        return nums[n - 1];
    }
    int findNth(span<int> nums1, span<int> nums2, int n){
        if (nums1.size() == 0) return findNth(nums2, n);
        if (nums2.size() == 0) return findNth(nums1, n);
        if (n == 1) return min(nums1[0], nums2[0]);
        if (nums1.size() > nums2.size()) return findNth(nums2, nums1, n);
        int half = min(n / 2, (int)nums1.size());
        int xval = nums1[half - 1], yval = nums2[half - 1];
        if (xval <= yval) {
            return findNth(nums1.subspan(half), nums2, n - half);
        } else {
            return findNth(nums1, nums2.subspan(half), n - half);
        }
    }
public:
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
        int c = nums1.size() + nums2.size();
        if (c == 0) return 0;
        if(!(c & 1)){
            return (findNth(nums1, nums2, c / 2 + 1) + findNth(nums1, nums2, c / 2)) / 2.0;
        }else{
            return findNth(nums1, nums2, c / 2 + 1);
        }
    }
};