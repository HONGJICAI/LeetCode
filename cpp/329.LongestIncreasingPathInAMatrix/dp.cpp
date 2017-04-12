class Solution {
public:
	int row;
	int col;
	vector<vector<int>> dp;
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		row = matrix.size();
		if(row==0)return 0;
		col = matrix[0].size();
		dp.resize(row);
		for (int i = 0; i<row; i++)
			dp[i].resize(col);
		for (int i = 0; i<row; i++)
			for (int j = 0; j<col; j++)
				dp[i][j] = 0;
		for (int i = 0; i<row; i++)
			for (int j = 0; j<col; j++)
				calc(i, j, matrix);
		int max = INT_MIN;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				if (dp[i][j]>max)
					max = dp[i][j];
		return max;
	}
	int calc(int i, int j, vector<vector<int>>& matrix) {
		int max = 1;
		int temp;
		if (i - 1>=0)
			if (matrix[i][j]>matrix[i - 1][j])
				if (dp[i - 1][j]>0)
					max = dp[i - 1][j] + 1>max ? dp[i - 1][j] + 1 : max;
				else {
					temp = calc(i - 1, j, matrix) + 1;
					max = temp>max ? temp : max;
				}
				if (i + 1<row)
					if (matrix[i][j]>matrix[i + 1][j])
						if (dp[i + 1][j]>0)
							max = dp[i + 1][j] + 1>max ? dp[i + 1][j] + 1 : max;
						else {
							temp = calc(i + 1, j, matrix) + 1;
							max = temp>max ? temp : max;
						}
						if (j - 1>=0)
							if (matrix[i][j]>matrix[i][j - 1])
								if (dp[i][j - 1]>0)
									max = dp[i][j - 1] + 1>max ? dp[i][j - 1] + 1 : max;
								else {
									temp = calc(i, j - 1, matrix) + 1;
									max = temp>max ? temp : max;
								}
								if (j + 1<col)
									if (matrix[i][j]>matrix[i][j + 1])
										if (dp[i][j + 1]>0)
											max = dp[i][j + 1] + 1>max ? dp[i][j + 1] + 1 : max;
										else {
											temp = calc(i, j + 1, matrix) + 1;
											max = temp>max ? temp : max;
										}
										dp[i][j] = max;
										return max;
	}
};
