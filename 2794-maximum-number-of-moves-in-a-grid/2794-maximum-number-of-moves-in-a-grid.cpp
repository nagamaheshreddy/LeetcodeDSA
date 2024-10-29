class Solution {
public:
     int dfs(int i,int j,int prev,vector<vector<int>>& grid,vector<vector<int>>&dp){
        int n=grid.size();
        int m=grid[0].size();

        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]<=prev)return 0;

        if(dp[i][j]!=-1)return dp[i][j];
        
        int upperRight=dfs(i-1,j+1,grid[i][j],grid,dp);
        int right=dfs(i,j+1,grid[i][j],grid,dp);
        int lowerRight=dfs(i+1,j+1,grid[i][j],grid,dp);

        return dp[i][j]=1+max(right,max(upperRight,lowerRight));
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));

        for(int i=0;i<n;i++){
            int count=dfs(i,0,0,grid,dp);
            ans=max(ans,count-1);
        }
        return ans;
    }
};