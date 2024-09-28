class Solution {
public:

    int  dfs(int i,int j,int rows,int cols,vector<vector<int>>& grid,vector<vector<int>>& vis){
            if(i<0 || i>=rows ||j<0 || j>=cols || vis[i][j]==1 || grid[i][j]==0)return 0;

            vis[i][j]=1;

            int a=dfs(i+1,j,rows,cols,grid,vis);
            int b=dfs(i-1,j,rows,cols,grid,vis);
            int c=dfs(i,j+1,rows,cols,grid,vis);
            int d=dfs(i,j-1,rows,cols,grid,vis);

            return 1+a+b+c+d;
        }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        vector<vector<int>>vis(rows,vector<int>(cols,-1));
        int count=0;
        int maxArea=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1 && vis[i][j]==-1){
                    count=dfs(i,j,rows,cols,grid,vis);
                    maxArea=max(maxArea,count);
                }
            }
        }
        return maxArea;
    }
};