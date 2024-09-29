class Solution {
public:

    void solve(int ind,vector<int>& subset,vector<int>& nums,vector<vector<int>>& ans){
        if(ind==nums.size()){
            ans.push_back(subset);
            return;
        }

        //NOTTAKE
        solve(ind+1,subset,nums,ans);

        //TAKE
        subset.push_back(nums[ind]);
        solve(ind+1,subset,nums,ans);
        subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>subset;

        solve(0,subset,nums,ans);
        return ans;
    }
};