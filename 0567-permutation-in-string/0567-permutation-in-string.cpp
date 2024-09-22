class Solution {
public:
    bool isPermutation(unordered_map<char,int>mp,string str){

        for(char ch:str){
            mp[ch]--;
            if(mp[ch]==0){
                mp.erase(ch);
            }
        }
        return mp.empty();
    }

    bool checkInclusion(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        unordered_map<char,int>mp1;
        for(char ch:s1)mp1[ch]++;
        unordered_map<char,int>mp2;

        int i=0,j=0;
        while(j<m){
            mp2[s2[j]]++;

            if(j-i+1==n){
                if(mp1==mp2){
                    return true;
                }
                mp2[s2[i]]--;
                if(mp2[s2[i]]==0)mp2.erase(s2[i]);
                i++;
            }
            j++;
        }
        return false;
    }
};