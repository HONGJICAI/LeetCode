class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result;
        if(numRows==0)return result;
        result.push_back(vector<int>(1,1));
        if(numRows==1)return result;
        vector<int>a;
        for(int row=1;row<numRows;++row){
            a.push_back(1);
            for(int i=1;i<row;++i)
                a.push_back(result[row-1][i]+result[row-1][i-1]);
            a.push_back(1);
            result.push_back(a);
            a.clear();
        }
        return result;
    }
};