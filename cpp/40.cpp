// sort_dfs.cpp
class Solution {
  vector<vector<int>> res;

public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> cur;
    dfs(candidates, cur, 0, target);
    return res;
  }
  void dfs(vector<int> &nums, vector<int> &cur, int i, int sum) {
    if (0 == sum) {
      res.push_back(cur);
      return;
    }
    for (int start = i; i < nums.size() && sum >= nums[i]; ++i) {
      if (i > start && nums[i] == nums[i - 1])
        continue;
      cur.push_back(nums[i]);
      dfs(nums, cur, i + 1, sum - nums[i]);
      cur.pop_back();
    }
  }
};
