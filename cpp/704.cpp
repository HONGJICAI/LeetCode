class Solution { // Runtime: 52 ms, faster than 87.93% of C++ online submissions
                 // for Binary Search.
public:
  int search(vector<int> &nums, int target) {
    if (auto it = lower_bound(begin(nums), end(nums), target);
        it != nums.end() and *it == target)
      return it - nums.begin();
    return -1;
  }
};