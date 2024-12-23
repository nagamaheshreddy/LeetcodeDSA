class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        int maxLength=0,j=0,i=0;

        while(j<n){
            mp[s[j]]++;

            if(mp.size()!=j-i+1){
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            maxLength=max(maxLength,j-i+1);
            j++;
        }

        
        return maxLength;
    }
};