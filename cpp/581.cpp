// O1SpaceOnTimeBeat95.cpp
class Solution {
public:
  int findUnsortedSubarray(vector<int> &nums) {
    int sum = 0, n = nums.size(), i, j;
    for (i = 0; i < n - 1 && nums[i] <= nums[i + 1]; ++i)
      ;
    for (j = n - 1; i < j && nums[j] >= nums[j - 1]; --j)
      ;
    if (i-- == j++)
      return 0;
    for (int k = i + 1; k < j; ++k) {
      while (i >= 0 && nums[k] < nums[i])
        --i;
      while (j < n && nums[k] > nums[j])
        ++j;
    }
    return j - i - 1;
  }
};
// sort.cpp
class Solution {
public:
  int findUnsortedSubarray(vector<int> &nums) {
    vector<int> res(nums.begin(), nums.end());
    sort(res.begin(), res.end());
    int sum = 0, n = nums.size(), i, j;
    for (i = 0; i < n && nums[i] == res[i]; ++i, ++sum)
      ;
    for (j = n - 1; i < j && nums[j] == res[j]; --j, ++sum)
      ;
    return n - sum;
  }
};
// stack.cpp
class Solution {
public:
  int findUnsortedSubarray(vector<int> &nums) {
    stack<int> st1, st2;
    int sum = 0, n = nums.size(), i, j;
    for (i = 0; i < n - 1 && nums[i] <= nums[i + 1]; ++i)
      st1.push(nums[i]);
    for (j = n - 1; i < j && nums[j] >= nums[j - 1]; --j)
      st2.push(nums[j]);
    if (i == j)
      return 0;
    for (int k = i; k <= j; ++k) {
      while (!st1.empty() && nums[k] < st1.top())
        st1.pop();
      while (!st2.empty() && nums[k] > st2.top())
        st2.pop();
    }
    return n - st1.size() - st2.size();
  }
};
