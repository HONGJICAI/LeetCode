class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(),times=n/2;
        for(int k=0;k<times;++k)
            for(int i=k;i<n-k-1;++i){
                int temp=matrix[k][i];
                matrix[k][i]=matrix[n-1-i][k];
                matrix[n-1-i][k]=matrix[n-1-k][n-1-i];
                matrix[n-1-k][n-1-i]=matrix[i][n-1-k];
                matrix[i][n-1-k]=temp;
            }
    }
};
