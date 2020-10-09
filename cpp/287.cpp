class Solution {
  // Runtime: 8 ms, faster than 98.62% of C++ online submissions for Find the
  // Duplicate Number. Memory Usage: 10.1 MB, less than 16.02% of C++ online
  // submissions for Find the Duplicate Number.
public:
  int findDuplicate(vector<int> &nums) {
    int slow = nums[0];
    int fast = nums[nums[0]];
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }
    for (fast = 0; fast != slow;) {
      fast = nums[fast];
      slow = nums[slow];
    }
    return slow;
  }
};