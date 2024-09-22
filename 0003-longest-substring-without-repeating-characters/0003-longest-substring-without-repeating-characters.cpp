class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(),longest=0;
        unordered_map<char,int>mp;

        int i=0,j=0;

        while(j<n){
            mp[s[j]]++;

            while(mp.size()!=j-i+1){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            longest=max(longest,j-i+1);
            j++;
        }
        
        return longest;
    }
};