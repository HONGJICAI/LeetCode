class Solution {
    vector<vector<int>> res;
    void dfs(vector<int>& nums, vector<int>& cur, int i, int sum) {
        if (0 == sum) {
            res.push_back(cur);
            return;
        }
        for (; i < nums.size() && sum >= nums[i]; ++i) {
            cur.push_back(nums[i]);
            dfs(nums, cur, i, sum - nums[i]);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ranges::sort(candidates);
        vector<int> cur;
        dfs(candidates, cur, 0, target);
        return res;
    }
};
