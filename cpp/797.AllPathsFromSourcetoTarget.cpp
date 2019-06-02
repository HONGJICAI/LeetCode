class Solution {
// Runtime: 72 ms, faster than 98.24% of C++ online submissions for All Paths From Source to Target.
// Memory Usage: 12.6 MB, less than 87.43% of C++ online submissions for All Paths From Source to Target.
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        vector<vector<int>> res;
        vector<int> path;
        function<void(int)> dfs = [&](int cur) {
            path.push_back(cur);
            if (cur == g.size() - 1)
                res.push_back(path);
            else for (auto dst:g[cur])
                dfs(dst);
            path.pop_back();
        };
        dfs(0);
        return res;
    }
};