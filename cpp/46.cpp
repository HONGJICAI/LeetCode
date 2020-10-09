// dfs.cpp
class Solution {
  vector<vector<int>> res;

public:
  vector<vector<int>> permute(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<bool> used(nums.size(), 0);
    vector<int> cur;
    dfs(nums, used, cur);
    return res;
  }
  void dfs(vector<int> &nums, vector<bool> &used, vector<int> &cur) {
    if (cur.size() == nums.size()) {
      res.push_back(cur);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (used[i] == 0) {
        used[i] = 1;
        cur.push_back(nums[i]);
        dfs(nums, used, cur);
        cur.pop_back();
        used[i] = 0;
      }
    }
  }
};
