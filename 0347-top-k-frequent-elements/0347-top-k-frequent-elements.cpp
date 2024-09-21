class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<pair<int,int>>freq;

        for(int &num:nums)mp[num]++;
        for(auto pair:mp){
            freq.push_back({pair.second,pair.first});
        }
        sort(freq.begin(),freq.end(),greater<pair<int,int>>());
        vector<int>ans;

        for(int i=0;i<k;i++){
            ans.push_back(freq[i].second);
        }
        return ans;
    }
};