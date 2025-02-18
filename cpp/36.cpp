// timeO243_spaceO9.cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            int nine[9] = {};
            for (int j = 0; j < 9; ++j)
                if (board[i][j] != '.')
                    if (nine[board[i][j] - '1']++ > 0)
                        return 0;
        }
        for (int i = 0; i < 9; ++i) {
            int nine[9] = {};
            for (int j = 0; j < 9; ++j)
                if (board[j][i] != '.')
                    if (nine[board[j][i] - '1']++ > 0)
                        return 0;
        }
        for (int m = 0; m < 9; ++m) {
            int nine[9] = {};
            for (int i = m / 3 * 3; i < m / 3 * 3 + 3; ++i)
                for (int j = 3 * (m % 3); j < 3 * (m % 3) + 3; ++j)
                    if (board[i][j] != '.')
                        if (nine[board[i][j] - '1']++ > 0)
                            return 0;
        }
        return 1;
    }
};
// timeO81_spaceO243.cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int ver[9][9] = {}, hor[9][9] = {}, chunk[9][9] = {};
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] != '.')
                    if (int num = board[i][j] - '1';
                        ver[i][num]++ > 0 || hor[j][num]++ > 0 ||
                        chunk[i / 3 * 3 + j / 3][num]++ > 0)
                        return 0;
        return 1;
    }
};
