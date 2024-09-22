class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy=0,profit=0,maxProfit=0,n=prices.size();
        minBuy=prices[0];

        for(int i=1;i<n;i++){
            profit=prices[i]-minBuy;
            minBuy=min(minBuy,prices[i]);
            maxProfit=max(maxProfit,profit);
        }
        return maxProfit;
    }
};