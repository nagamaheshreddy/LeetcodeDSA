class Solution {
public:

    int dfs(int i,int j,int n,int m,long long prev,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(i<0 || i>=n || j<0 || j>=m || prev<=matrix[i][j])return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int up=dfs(i-1,j,n,m,matrix[i][j],matrix,dp);
        int down=dfs(i+1,j,n,m,matrix[i][j],matrix,dp);
        int left=dfs(i,j-1,n,m,matrix[i][j],matrix,dp);
        int right=dfs(i,j+1,n,m,matrix[i][j],matrix,dp);

        return dp[i][j]=1+max(up,max(down,max(left,right))); 
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int  ans=0;
        long long prev=LLONG_MAX;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=dfs(i,j,n,m,prev,matrix,dp);
                ans=max(ans,count);
            }
        }
        return ans;
    }
};