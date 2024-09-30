class Solution {
public:
    bool solve(int ind,vector<int>&nums,vector<int>&memo){
        if(ind>=nums.size()-1)return true;

        if(memo[ind]!=-1)return memo[ind];

        int jumps=nums[ind];
        for(int i=1;i<=jumps;i++){
            if(solve(i+ind,nums,memo)){
                return memo[ind]=true;
            }
        }
        return memo[ind]=false;
    }
    bool canJump(vector<int>& nums) {
       int n=nums.size();
       vector<int>memo(n,-1);
       return solve(0,nums,memo);
        
    }
};