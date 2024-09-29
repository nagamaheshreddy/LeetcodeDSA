class Solution {
public:
void solve(int start,vector<int>& cand,int target,vector<int>& subset,vector<vector<int>>& ans){
        if(target<0)return;
        if(target==0){
            ans.push_back(subset);
            return;
        }


        for(int i=start;i<cand.size();i++){
            if(i!=start && cand[i]==cand[i-1])continue;

            subset.push_back(cand[i]);
            solve(i+1,cand,target-cand[i],subset,ans);
            subset.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        vector<vector<int>>ans;
        vector<int>subset;
        sort(cand.begin(),cand.end());

        solve(0,cand,target,subset,ans);

        return ans;
    }
};