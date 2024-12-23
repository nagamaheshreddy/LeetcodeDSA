class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mp;
        for(int num:nums)mp[num]++;
        int maxCount=0;

        for(auto pair:mp){
            int num=pair.first;
            if(mp.find(num-1)==mp.end()){
                int count=0;
                while(mp.find(num)!=mp.end()){
                    count++;
                    num++;
                }
                maxCount=max(maxCount,count);
            }
        }
        return maxCount;
    }
};