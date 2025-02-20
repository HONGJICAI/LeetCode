// iteration-0ms.cpp
class Solution {
  public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result{{1}};
        vector<int> a;
        for (int row = 1; row < numRows; ++row) {
            a.push_back(1);
            for (int i = 1; i < row; ++i)
                a.push_back(result[row - 1][i] + result[row - 1][i - 1]);
            a.push_back(1);
            result.push_back(move(a));
        }
        return result;
    }
};