class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size();

        map<int,int>mp;
        for(int i=0;i<n;i++){
            int req=target-nums[i];
            if(mp.find(req)!=mp.end()){
                ans.push_back(mp[req]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};