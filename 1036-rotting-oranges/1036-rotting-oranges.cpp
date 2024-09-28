class Solution {
public:
    bool isValid(int x,int y,int rows,int cols){
        if(x<0 || x>=rows || y<0 || y>=cols )return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        queue<pair<int,int>>q;
        int rotten=0,fresh=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    rotten++;
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        vector<int>dir_x={-1,1,0,0};
        vector<int>dir_y={0,0,-1,1};

        
        int minutes=0;

        while(!q.empty()){
            int n=q.size();

            for(int i=0;i<n;i++){
                  auto pair=q.front();
                  q.pop();
                  int x=pair.first;
                  int y=pair.second;

                  for(int k=0;k<4;k++){
                    int child_x=x+dir_x[k];
                    int child_y=y+dir_y[k];

                    if(isValid(child_x,child_y,rows,cols) && grid[child_x][child_y]==1){
                        q.push({child_x,child_y});
                        grid[child_x][child_y]=0;
                        fresh--;
                    }
                  }
            }
            if(!q.empty())minutes++;
        }
        if(fresh==0)return minutes;
        return -1;
    }
};