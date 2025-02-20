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
// construct permutation from the first i elements
class Solution2 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res = {{nums[0]}};
        for (int i = 1; i < nums.size(); ++i) {
            vector<vector<int>> new_res;
            for (auto& v : res) {
                for (int j = 0; j <= v.size(); ++j) {
                    vector<int> new_v = v;
                    new_v.insert(new_v.begin() + j, nums[i]);
                    new_res.push_back(new_v);
                }
            }
            res = move(new_res);
        }
        return res;
    }
};