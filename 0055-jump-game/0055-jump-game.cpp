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
       int goal=n-1;

       for(int i=n-1;i>=0;i--){
            if(i+nums[i]>=goal){
                goal=i;
            }
       }
       return goal==0;
        
    }
};