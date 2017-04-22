class NumMatrix {
vector<vector<int>>dp;
public:
NumMatrix(vector<vector<int>> matrix) {
    int row=matrix.size();
    if(row==0)return;
    int col=matrix[0].size();
    dp=matrix;
    for(int i=1;i<row;++i)
	for(int j=0;j<col;++j)
	    dp[i][j]+=dp[i-1][j];
    for(int i=0;i<row;++i)
	for(int j=1;j<col;++j)
	    dp[i][j]+=dp[i][j-1];
}

int sumRegion(int row1, int col1, int row2, int col2) {
    int b=row1>0&&col1>0?dp[row1-1][col1-1]:0,c=col1>0?dp[row2][col1-1]:0,d=row1>0?dp[row1-1][col2]:0;
    return dp[row2][col2]+b-c-d;
}
};

/**
* Your NumMatrix object will be instantiated and called as such:
* NumMatrix obj = new NumMatrix(matrix);
* int param_1 = obj.sumRegion(row1,col1,row2,col2);
*/
