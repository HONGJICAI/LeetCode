class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        if(row==0)return 0;
        int col=matrix[0].size();
        int j=col-1,i=0;
        while(i<row&&j>=0){
            if(matrix[i][j]>target)
                --j;
            else if(matrix[i][j]<target)
                ++i;
            else
                return 1;
        }
        return 0;
    }
};