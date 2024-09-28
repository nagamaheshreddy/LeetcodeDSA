class Solution {
public:

void dfs(int i,int j,int rows,int cols,vector<vector<char>>& grid){
        if(i<0 || i>=rows ||j<0 || j>=cols  || grid[i][j]=='X' || grid[i][j]=='Z')return ;

        grid[i][j]='Z';

        dfs(i+1,j,rows,cols,grid);
        dfs(i-1,j,rows,cols,grid);
        dfs(i,j+1,rows,cols,grid);
        dfs(i,j-1,rows,cols,grid);
    }
    void solve(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int count=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i==0 || i==rows-1 || j==0 || j==cols-1){
                    dfs(i,j,rows,cols,grid);
                }
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='Z')grid[i][j]='O';
                else if(grid[i][j]=='O')grid[i][j]='X';
            }
        }
    }
};