class Solution {
public:
    void solve(int ind,vector<int>&nums,vector<int>&subset,vector<vector<int>>&ans,vector<int>&vis){
        if(subset.size()==nums.size()){
            ans.push_back(subset);
            return ;
        }

        for(int i=0;i<nums.size();i++){
            if(vis[i]==0){
                subset.push_back(nums[i]);
                vis[i]=1;
                solve(i+1,nums,subset,ans,vis);
                subset.pop_back();
                vis[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>vis(n,0);
        vector<int>subset;

        solve(0,nums,subset,ans,vis);

        return ans;
    }
};