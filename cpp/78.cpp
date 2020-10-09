// dfs_recursion.cpp
class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<int> cur;
    vector<vector<int>> res;
    dfs(cur, res, nums, 0);
    return res;
  }
  void dfs(vector<int> &cur, vector<vector<int>> &res, vector<int> &nums,
           int i) {
    if (nums.size() == i) {
      res.push_back(cur);
      return;
    }
    cur.push_back(nums[i]);
    dfs(cur, res, nums, i + 1);
    cur.pop_back();
    dfs(cur, res, nums, i + 1);
  }
};
// smart_iteration.cpp
class Solution {
public:
  vector<vector<int>> subsets(vector<int> &S) {
    sort(S.begin(), S.end());
    int elem_num = S.size();
    int subset_num = pow(2, elem_num);
    vector<vector<int>> subset_set(subset_num, vector<int>());
    for (int i = 0; i < elem_num; i++)
      for (int j = 0; j < subset_num; j++)
        if ((j >> i) & 1)
          subset_set[j].push_back(S[i]);
    return subset_set;
  }
};
