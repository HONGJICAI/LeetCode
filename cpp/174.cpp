class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m-1][n-1] = max(-dungeon[m-1][n-1], 0);
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (j + 1 == n && i + 1 == m) continue;
                int rightPathHp = j + 1 < n ? max(dp[i][j + 1] - dungeon[i][j], 0) : INT_MAX;
                int bottomPathHp = i + 1 < m ? max(dp[i + 1][j ] - dungeon[i][j], 0) : INT_MAX;
                dp[i][j] = min(rightPathHp, bottomPathHp);
            }
        }
        return dp[0][0] + 1;
    }
};