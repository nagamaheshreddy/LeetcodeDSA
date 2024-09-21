class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0,conseq=1;
        int n=nums.size();

        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
               conseq++;
               ans=max(ans,conseq); 
            }else if(nums[i]!=nums[i-1]){
                conseq=1;
            }
        }
        ans=max(ans,conseq);
        if(nums.size()==0)return 0;
        return ans;
    }
};