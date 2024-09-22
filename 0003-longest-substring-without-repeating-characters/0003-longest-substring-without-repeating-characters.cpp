class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(),longest=0;
        unordered_map<char,int>mp;

        for(int i=0;i<n;i++){
            mp.clear();
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                if(mp.size()!=j-i+1){
                    break;
                }
            longest=max(longest,j-i+1);
            }
        }
        return longest;
    }
};