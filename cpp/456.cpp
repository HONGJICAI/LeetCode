class Solution {
  // Runtime: 520 ms, faster than 24.35% of C++ online submissions for 132
  // Pattern. Memory Usage: 9.9 MB, less than 89.07% of C++ online submissions
  // for 132 Pattern.
public:
  bool find132pattern(vector<int> &nums) {
    if (nums.size() < 3)
      return false;
    for (auto i = nums[0], j = 1; j + 1 < nums.size(); j++) {
      if (i < nums[j]) {
        if (find_if(begin(nums) + j + 1, end(nums),
                    [l = i, m = nums[j]](auto &a) {
                      return l < a and a < m;
                    }) != end(nums))
          return true;
      } else
        i = nums[j];
    }
    return false;
  }
};
class Solution {
  // Runtime: 292 ms, faster than 34.78% of C++ online submissions for 132
  // Pattern. Memory Usage: 10.6 MB, less than 33.33% of C++ online submissions
  // for 132 Pattern.
public:
  bool find132pattern(vector<int> &nums) {
    if (nums.size() < 3)
      return false;
    auto k = vector<int>{next(begin(nums), 2), end(nums)};
    sort(begin(k), end(k));
    for (auto i = nums[0], j = 1; j + 1 < nums.size(); j++) {
      if (i < nums[j]) {
        auto it = upper_bound(begin(k), end(k), i);
        if (it != end(k) and *it < nums[j])
          return true;
      } else
        i = nums[j];
      k.erase(lower_bound(begin(k), end(k), nums[j + 1]));
    }
    return false;
  }
};
class Solution {
  // Runtime: 24 ms, faster than 88.49% of C++ online submissions for 132
  // Pattern. Memory Usage: 10.3 MB, less than 60.77% of C++ online submissions
  // for 132 Pattern.
public:
  bool find132pattern(vector<int> &nums) {
    int s3 = INT_MIN;
    stack<int> st;
    for (auto it = rbegin(nums); it != rend(nums); ++it) {
      if (*it < s3)
        return true;
      else
        while (!st.empty() && *it > st.top()) {
          s3 = st.top();
          st.pop();
        }
      st.push(*it);
    }
    return false;
  }
};