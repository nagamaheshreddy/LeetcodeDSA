class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0,conseq=0;
        unordered_set<int>s;
        for(int num:nums)s.insert(num);

        for(int num:nums){
            conseq=0;
            if(s.find(num+1)==s.end()){
                while(s.find(num)!=s.end()){
                    num--;
                    conseq++;
                }
                ans=max(ans,conseq);
            }
        }
        return ans;
    }
};