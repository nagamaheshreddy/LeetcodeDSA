class Solution {
public:
    void solve(int ind,vector<int>&subset,vector<int>&nums,vector<vector<int>>&ans,set<vector<int>>&s){
        if(ind==nums.size()){
            s.insert(subset);
            return;
        }

        solve(ind+1,subset,nums,ans,s);

        subset.push_back(nums[ind]);
        solve(ind+1,subset,nums,ans,s);
        subset.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>subset;
        set<vector<int>>s;
        sort(nums.begin(),nums.end());

        solve(0,subset,nums,ans,s);

        for(auto subset:s){
            ans.push_back(subset);
        }

        return ans;
    }
};