class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int ans=0,i=0,j=0;
        unordered_map<char,int>mp;

        while(j<n){
            mp[s[j]]+=1;

            while(mp.size()!=j-i+1 && i<n){
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};