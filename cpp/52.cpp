// smarthash+dfs.cpp
class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> flag(5 * n, 1);
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                res++;
                return;
            }
            for (int j = 0; j < n; ++j)
                if (flag[j] && flag[n + i + j] && flag[4 * n + i - j]) {
                    flag[j] = flag[n + i + j] = flag[4 * n + i - j] = 0;
                    dfs(i + 1);
                    flag[j] = flag[n + i + j] = flag[4 * n + i - j] = 1;
                }
        };
        dfs(0);
        return res;
    }
};