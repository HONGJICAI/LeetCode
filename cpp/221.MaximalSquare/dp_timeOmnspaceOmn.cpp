class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size();
        if(row==0)return 0;
        int col=matrix[0].size(),max=0;
        vector<vector<int>>dp(row,vector<int>(col,0));
        for(int i=0;i<row;++i){
            dp[i][0]=matrix[i][0]-'0';
            max=max>dp[i][0]?max:dp[i][0];
        }
        for(int i=0;i<col;++i){
            dp[0][i]=matrix[0][i]-'0';
            max=max>dp[0][i]?max:dp[0][i];
        }
        for(int i=1;i<row;++i)
            for(int j=1;j<col;++j)
                if(matrix[i][j]=='1'){
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1],dp[i][j-1])+1;
                    max=max>dp[i][j]?max:dp[i][j];
                }
        return max*max;
    }
    int min(int a,int b,int c){
        if(a>b)
            return b<c?b:c;
        return a<c?a:c;
    }
};
