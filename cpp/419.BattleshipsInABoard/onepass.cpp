class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count=0,row=board.size();
        if(row==0)return 0;
        int col=board[0].size();
        for(int i=0;i<row;++i)
            for(int j=0;j<col;++j)
                count+=board[i][j]=='X'&&(j==0||board[i][j-1]!='X')&&(i==0||board[i-1][j]!='X');
        return count;
    }
};
