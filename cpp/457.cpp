class Solution {
  // Runtime: 4 ms, faster than 88.75% of C++ online submissions for Circular
  // Array Loop. Memory Usage: 8.4 MB, less than 75.74% of C++ online
  // submissions for Circular Array Loop.
public:
  bool circularArrayLoop(vector<int> &nums) {
    vector<int> visited(nums.size(), 0);
    auto go = [&](int i) -> int {
      if (nums[i] > 0)
        return (i + nums[i]) % nums.size();
      else if (i + nums[i] < 0) {
        int offset = abs(i + nums[i]) % nums.size();
        return offset == 0 ? i : (int)nums.size() - offset;
      } else
        return i + nums[i];
    };
    for (int i = 0; i < nums.size(); ++i) {
      if (not visited[i]) {
        vector<int> curCircle(nums.size(), 0);
        curCircle[i] = 1;
        for (int start = go(i), dir = nums[i] > 0; (nums[start] > 0) == dir;) {
          if (curCircle[start])
            if (start != go(start))
              return true;
            else
              break;
          curCircle[start] = visited[start] = 1;
          start = go(start);
        }
      }
    }
    return false;
  }
};