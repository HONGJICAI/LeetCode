class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m==0)return vector<int>();
        int n=matrix[0].size(),i=0,j=0,k=1,sum=m*n;
        vector<int>res(sum);
        res[0]=matrix[0][0];
        while(k<sum){
            while(i-1>=0&&j+1<n)
                res[k++]=matrix[--i][++j];
            if(j+1<n)
                res[k++]=matrix[i][++j];
            else if(i+1<m)
                res[k++]=matrix[++i][j];
            while(i+1<m&&j-1>=0)
                res[k++]=matrix[++i][--j];
            if(i+1<m)
                res[k++]=matrix[++i][j];
            else if(j+1<n)
                res[k++]=matrix[i][++j];
        }
        return res;
    }
};
