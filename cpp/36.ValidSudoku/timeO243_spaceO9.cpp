class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int>nine(9,0);
        for(int i=0;i<9;++i){
            nine.assign(9,0);
            for(int j=0;j<9;++j)
                if(board[i][j]!='.')
                    if(nine[board[i][j]-'1']++>0)
                        return 0;
        }
        for(int i=0;i<9;++i){
            nine.assign(9,0);
            for(int j=0;j<9;++j)
                if(board[j][i]!='.')
                    if(nine[board[j][i]-'1']++>0)
                        return 0;
        }
        for(int m=0;m<9;++m){
            nine.assign(9,0);
            for(int i=m/3*3;i<m/3*3+3;++i)
                for(int j=3*(m%3);j<3*(m%3)+3;++j)
                    if(board[i][j]!='.')
                        if(nine[board[i][j]-'1']++>0)
                            return 0;
        }
        return 1;
    }
};
