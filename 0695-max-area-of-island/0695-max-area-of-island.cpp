class Solution {
public:

    int  dfs(int i,int j,int rows,int cols,vector<vector<int>>& grid){
            if(i<0 || i>=rows ||j<0 || j>=cols || grid[i][j]==0)return 0;

            grid[i][j]=0;

            int a=dfs(i+1,j,rows,cols,grid);
            int b=dfs(i-1,j,rows,cols,grid);
            int c=dfs(i,j+1,rows,cols,grid);
            int d=dfs(i,j-1,rows,cols,grid);

            return 1+a+b+c+d;
        }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        int count=0;
        int maxArea=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    count=dfs(i,j,rows,cols,grid);
                    maxArea=max(maxArea,count);
                }
            }
        }
        return maxArea;
    }
};