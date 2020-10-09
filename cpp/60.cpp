// timeOnk.cpp
class Solution {
public:
  string getPermutation(int n, int k) {
    string str = "";
    for (int i = 1; i <= n; ++i)
      str += char(i + '0');
    for (int i = 1; i < k; ++i)
      nextPermutation(str);
    return str;
  }
  void nextPermutation(string &nums) {
    int i = 0, j = nums.size() - 1, n = nums.size();
    while (j > 0 && nums[j] <= nums[j - 1])
      --j;
    if (j - 1 >= 0) {
      int minIndex = j;
      for (int k = j + 1; k < n; ++k)
        if (nums[k] > nums[j - 1])
          minIndex = nums[j] < nums[k] ? j : k;
      swap(nums[j - 1], nums[minIndex]);
      sort(nums.begin() + j, nums.end());
    } else
      sort(nums.begin(), nums.end());
  }
};
