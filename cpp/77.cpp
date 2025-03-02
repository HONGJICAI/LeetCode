// dfs.cpp
class Solution {
    void dfs(vector<int>& cur, vector<vector<int>>& res, int i, int n, int k) {
        if (0 == k) {
            res.push_back(cur);
            return;
        }
        for (; i <= n && n - i + 1 >= k; ++i) {
            cur.push_back(i);
            dfs(cur, res, i + 1, n, k - 1);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        vector<vector<int>> res;
        dfs(cur, res, 1, n, k);
        return res;
    }
};
// iteration.cpp
class Solution2 {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        int i = 0;
        vector<int> p(k, 0);
        while (i >= 0) {
            p[i]++;
            if (p[i] > n)
                --i;
            else if (i == k - 1)
                result.push_back(p);
            else {
                ++i;
                p[i] = p[i - 1];
            }
        }
        return result;
    }
};
