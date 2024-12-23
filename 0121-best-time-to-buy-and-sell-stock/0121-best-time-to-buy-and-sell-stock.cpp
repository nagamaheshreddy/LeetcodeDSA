class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int smallest=prices[0];
        int profit=0,ans=0;

        for(int i=1;i<n;i++){
            profit=prices[i]-smallest;
            ans=max(ans,profit);
            smallest=min(smallest,prices[i]);
        }
        return ans;
    }
};