class Solution {
public:
    void solve(int start,vector<int>& cand,int target,vector<int>& subset,vector<vector<int>>& ans){
        if(target<0)return;
        if(target==0){
            ans.push_back(subset);
            return;
        }


        for(int i=start;i<cand.size();i++){
            subset.push_back(cand[i]);
            solve(i,cand,target-cand[i],subset,ans);
            subset.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>>ans;
        vector<int>subset;

        solve(0,cand,target,subset,ans);

        return ans;
    }
};