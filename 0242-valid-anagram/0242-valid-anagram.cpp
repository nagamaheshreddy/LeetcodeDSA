class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;

        for(char ch:s)mp[ch]++;
        
        for(char ch:t){
            if(mp.count(ch)>0){
                mp[ch]--;
                if(mp[ch]==0)mp.erase(ch);
            }else{
                return false;
            }
        }
        return mp.size()==0;
    }
};