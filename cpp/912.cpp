class Solution {
  // Runtime: 56 ms, faster than 95.85% of C++ online submissions for Sort an
  // Array. Memory Usage: 17.2 MB, less than 13.35% of C++ online submissions
  // for Sort an Array.
public:
  vector<int> sortArray(vector<int> &nums) {
    vector<int> refmap(50000 + 50000 + 1, 0);
    for (int I : nums)
      refmap[I + 50000]++;
    int idx = 0;
    for (int i = 0; i < refmap.size(); i++)
      while (refmap[i]--)
        nums[idx++] = i - 50000;
    return nums;
  }
};