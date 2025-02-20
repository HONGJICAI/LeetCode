// 1-9ms.cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0)
            return 0;
        int col = matrix[0].size();
        int j = col - 1, i = 0;
        while (i < row && j >= 0) {
            if (matrix[i][j] > target)
                --j;
            else if (matrix[i][j] < target)
                ++i;
            else
                return 1;
        }
        return 0;
    }
};
class SolutionStdlib {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto rowIt = lower_bound(matrix.begin(), matrix.end(), target,
                                 [](const vector<int>& v, int target) {
                                     return v.front() < target;
                                 });
        if (rowIt != matrix.end() && rowIt->front() == target)
            return true;
        if (rowIt == matrix.begin())
            return false;
        rowIt -= 1;
        auto colIt = lower_bound(rowIt->begin(), rowIt->end(), target);
        return colIt != rowIt->end() && *colIt == target;
    }
};