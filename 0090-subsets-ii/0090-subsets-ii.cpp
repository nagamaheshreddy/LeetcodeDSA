class Solution {
public:
    void solve(int start,vector<int>&subset,vector<int>&nums,vector<vector<int>>&ans){
        ans.push_back(subset);

        for(int i=start;i<nums.size();i++){
            if(i!=start && nums[i]==nums[i-1])continue;

            subset.push_back(nums[i]);
            solve(i+1,subset,nums,ans);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>subset;
        sort(nums.begin(),nums.end());

        solve(0,subset,nums,ans);

        return ans;
    }
};