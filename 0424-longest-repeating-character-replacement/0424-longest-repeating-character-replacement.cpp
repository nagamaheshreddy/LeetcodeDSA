class Solution {
public:
    int getMaxChar(unordered_map<char,int>&mp){
        int maxi=0;
        for(auto pair:mp){
            maxi=max(maxi,pair.second);
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int>mp;
        int i=0,j=0,maxi=0,longest=0;

        while(j<n){
            mp[s[j]]++;

            while((j-i+1)-getMaxChar(mp)>k){
                mp[s[i]]--;
                i++;
            }
            longest=max(longest,j-i+1);
            j++;
        }
        return longest;
    }
};