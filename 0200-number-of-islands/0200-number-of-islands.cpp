class Solution {
public:
    void dfs(int i,int j,int rows,int cols,vector<vector<char>>& grid,vector<vector<int>>& vis){
        if(i<0 || i>=rows ||j<0 || j>=cols || vis[i][j]==1 || grid[i][j]=='0')return ;

        vis[i][j]=1;

        dfs(i+1,j,rows,cols,grid,vis);
        dfs(i-1,j,rows,cols,grid,vis);
        dfs(i,j+1,rows,cols,grid,vis);
        dfs(i,j-1,rows,cols,grid,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        vector<vector<int>>vis(rows,vector<int>(cols,-1));
        int islands=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1' && vis[i][j]==-1){
                    dfs(i,j,rows,cols,grid,vis);
                    islands++;
                }
            }
        }
        return islands;

    }
};