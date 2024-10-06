class Solution {
public:
    int solve(int ind,int buy,vector<int>&prices,vector<vector<int>>&dp){
        if(ind>=prices.size())return 0;

        if(dp[ind][buy]!=-1)return dp[ind][buy];

        int profit=0;
        if(buy){
            int buys=-prices[ind]+solve(ind+1,0,prices,dp);
            int notBuy=0+solve(ind+1,1,prices,dp);
            profit=max(buys,notBuy);
        }else{
            int sell=prices[ind]+solve(ind+2,1,prices,dp);
            int notSell=0+solve(ind+1,0,prices,dp);
            profit=max(sell,notSell);
        }

        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};