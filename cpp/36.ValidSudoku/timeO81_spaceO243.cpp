class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int ver[9][9]={0},hor[9][9]={0},chunk[9][9]={0},num;
        for(int i=0;i<9;++i)
            for(int j=0;j<9;++j)
                if((num=board[i][j])!='.')
                    if(ver[i][num-'1']++>0||hor[j][num-'1']++>0||chunk[i/3*3+j/3][num-'1']++>0)
                        return 0;
        return 1;
    }
};
