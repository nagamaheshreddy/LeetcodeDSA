class Solution {
public:

    int solve(int ind,vector<int>&cost){
        if(ind==0 || ind==1)return 0;

        int first=solve(ind-1,cost)+cost[ind-1];
        int second=solve(ind-2,cost)+cost[ind-2];

        return min(first,second);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==2)return min(cost[0],cost[1]);
        vector<int>dp(n+1,0);

        for(int i=2;i<=n;i++){
            int first=dp[i-1]+cost[i-1];
            int second=dp[i-2]+cost[i-2];
            dp[i]=min(first,second);
        }
        return dp[n];

    }
};