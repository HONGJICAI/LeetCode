class Solution {
//Runtime: 52 ms, faster than 99.27% of C++ online submissions for Spiral Matrix III.
//Memory Usage: 13.6 MB, less than 60.22% of C++ online submissions for Spiral Matrix III.
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r, int c) {
        vector<vector<int>> res = {{r, c}};
        vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        int curDir = 0;
        for (int n = 0; res.size() < R * C; ++n) {
            auto [dirX,dirY] = dirs[curDir++%4];
            for (int i = 0; i < n / 2 + 1; ++i) {
                r += dirY, c += dirX;
                if (0 <= r && r < R && 0 <= c && c < C)
                    res.push_back({r, c});
            }
        }
        return res;
    }
};