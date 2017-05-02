class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row=nums.size();
        if(row==0)return nums;
        int col=nums[0].size(),k=0;
        if(r*c!=row*col)return nums;
        vector<vector<int>>reshape(r,vector<int>(c));
        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j,++k)
                reshape[i][j]=nums[k/col][k%col];
        return reshape;
    }
};
