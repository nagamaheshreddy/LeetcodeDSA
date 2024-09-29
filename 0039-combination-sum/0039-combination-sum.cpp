class Solution {
public:
    void solve(int ind,vector<int>& cand,int target,vector<int>& subset,vector<vector<int>>& ans){
        if(target<0 || ind>=cand.size())return;
        if(target==0){
            ans.push_back(subset);
            return;
        }

        solve(ind+1,cand,target,subset,ans);

        subset.push_back(cand[ind]);
        solve(ind,cand,target-cand[ind],subset,ans);
        subset.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>>ans;
        vector<int>subset;

        solve(0,cand,target,subset,ans);

        return ans;
    }
};