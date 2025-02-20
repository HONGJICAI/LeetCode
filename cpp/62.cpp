// dp-0ms.cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1)
            return 1;
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m - 1][n - 1];
    }
};
// math
class Solution2 {
public:
    int uniquePaths(int m, int n) {
        if (n > m)
            return uniquePaths(n, m);
        --m, --n;
        double ret = 1.0;
        for (int i = m + 1; i <= m + n; ++i)
            ret *= i;
        for (int i = 2; i <= n; ++i)
            ret /= i;
        return ret;
    }
};