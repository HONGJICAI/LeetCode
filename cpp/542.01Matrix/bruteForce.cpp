class Solution {
    int row,col;
    bool valid(int x, int y) {
        if (x < 0 || x >= row || y < 0 || y >= col)
            return 0;
        return 1;
    }
    int bruteForce(vector<vector<int>>&matrix,int i,int j) {
        int len = 1;
        while (1) {
            int x = 0, y = len;
            while (0 <= y) {
                if ((valid(i + x, j + y) && matrix[i + x][j + y] == 0) ||
                    (valid(i - x, j + y) && matrix[i - x][j + y] == 0) ||
                    (valid(i + x, j - y) && matrix[i + x][j - y] == 0) ||
                    (valid(i - x, j - y) && matrix[i - x][j - y] == 0))
                    return len;
                x++, y--;
            }
            ++len;
        }
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        row=matrix.size();
        col=matrix[0].size();
        vector<vector<int>>res(row,vector<int>(col,0));
        for(int i=0;i<row;++i)
            for(int j=0;j<col;++j)
                if(matrix[i][j])
                    res[i][j]=bruteForce(matrix,i,j);
        return res;
    }
};
