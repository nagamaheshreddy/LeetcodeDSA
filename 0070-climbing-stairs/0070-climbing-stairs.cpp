class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n==0 || n==1)return 1;
        if(dp[n]!=-1)return dp[n];

        int first=solve(n-1,dp);
        int second=solve(n-2,dp);

        return dp[n]=first+second;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        dp[0]=dp[1]=1;
        if(n==0 || n==1)return 1;
        
        int curr,prev1=1,prev2=1;

        for(int i=2;i<=n;i++){
            curr=prev1+prev2;
            prev1=prev2;
            prev2=curr;
        }
        return curr;
        
    }
};