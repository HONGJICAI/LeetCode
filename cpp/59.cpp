class Solution {
    void changeDirt(int& x, int& y, int& towards) {
        towards = (towards + 1) % 4;
        switch (towards) {
        case 0:
            x = 1;
            y = 0;
            break;
        case 1:
            x = 0;
            y = 1;
            break;
        case 2:
            x = -1;
            y = 0;
            break;
        case 3:
            x = 0;
            y = -1;
            break;
        }
    }

public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        result[0][0] = 1;
        int x = 1, y = 0, towards = 0, i = 0, j = 0, current = 2;
        while (current <= n * n) {
            if (j + x < n && j + x >= 0 && i + y < n && i + y >= 0 &&
                result[i + y][j + x] == 0) {
                j += x;
                i += y;
                result[i][j] = current++;
            } else {
                changeDirt(x, y, towards);
            }
        }
        return result;
    }
};
