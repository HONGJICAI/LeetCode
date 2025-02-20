class Solution {
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur,
             int i) {
        res.push_back(cur);
        if (i == nums.size())
            return;
        for (int start = i; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            cur.push_back(nums[i]);
            dfs(nums, res, cur, i + 1);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ranges::sort(nums);
        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums, res, cur, 0);
        return res;
    }
};
