// dfs.cpp
class Solution {
    void dfs(vector<string>& res, string& cur, int left, int right, int n) {
        if (left + right == n * 2) {
            res.push_back(cur);
            return;
        }
        if (left < n) {
            cur += '(';
            dfs(res, cur, left + 1, right, n);
            cur.pop_back();
        }
        if (left > right) {
            cur += ')';
            dfs(res, cur, left, right + 1, n);
            cur.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        dfs(res, s, 0, 0, n);
        return res;
    }
};