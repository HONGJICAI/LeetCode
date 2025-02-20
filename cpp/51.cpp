// simplehash+dfs+9ms.cpp
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> r(n, string(n, '.'));
        vector<vector<string>> res;
        unordered_set<int> ver, lTilt, rTilt;
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                res.push_back(r);
                return;
            }
            for (int j = 0; j < n; ++j)
                if (!ver.contains(j) && !lTilt.contains(i - j) &&
                    !rTilt.contains(i + j)) {
                    ver.insert(j), lTilt.insert(i - j), rTilt.insert(i + j);
                    r[i][j] = 'Q';
                    dfs(i + 1);
                    r[i][j] = '.';
                    ver.erase(j), lTilt.erase(i - j), rTilt.erase(i + j);
                }
        };
        dfs(0);
        return res;
    }
};
// smarthash+dfs+3ms.cpp
class Solution2 {
    vector<int> flag;
    vector<vector<string>> res;
    vector<string> r;
    int n;
    void dfs(int i) {
        if (i == n) {
            res.push_back(r);
            return;
        }
        for (int j = 0; j < n; ++j)
            if (flag[j] && flag[n + i + j] && flag[4 * n + i - j]) {
                flag[j] = flag[n + i + j] = flag[4 * n + i - j] = 0;
                r[i][j] = 'Q';
                dfs(i + 1);
                r[i][j] = '.';
                flag[j] = flag[n + i + j] = flag[4 * n + i - j] = 1;
            }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        string str(n, '.');
        this->n = n;
        r.assign(n, str);
        flag.assign(5 * n, 1);
        dfs(0);
        return res;
    }
};
