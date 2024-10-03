class Solution {
public:
    int solve(int ind,int target,vector<int>&nums,vector<vector<int>>&memo){
        if(target==0)return true;
        if(ind<0)return false;

        if(memo[ind][target]!=-1)return memo[ind][target];

        bool notTake=solve(ind-1,target,nums,memo);
        bool take=false;
        if(nums[ind]<=target){
            take=solve(ind-1,target-nums[ind],nums,memo);
        }
        return memo[ind][target]=take||notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)return false;
        vector<vector<int>>memo(n+1,vector<int>(sum,-1));

        int target=sum/2;
        return solve(n-1,target,nums,memo);
    }
};