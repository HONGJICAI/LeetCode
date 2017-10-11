class Solution {
    int row,col;
    int dfs(vector<vector<int>>&grid,vector<vector<int>>&visited,int i,int j){
        if(i<0||i>=row||j<0||j>=col||visited[i][j]||grid[i][j]==0)
            return 0;
        visited[i][j]=1;
        return 1+dfs(grid,visited,i+1,j)+dfs(grid,visited,i,j+1)+dfs(grid,visited,i-1,j)+dfs(grid,visited,i,j-1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row=grid.size();
        if(row==0)return 0;
        col=grid[0].size();
        int maxArea=0;
        vector<vector<int>>visited(row,vector<int>(col,0));
        for(int i=0;i<row;++i)
            for(int j=0;j<col;++j)
                if(visited[i][j]==0&&grid[i][j]==1)
                    maxArea=max(maxArea,dfs(grid,visited,i,j));
        return maxArea;
    }
};
