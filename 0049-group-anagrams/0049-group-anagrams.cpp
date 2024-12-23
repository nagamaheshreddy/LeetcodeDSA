class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        map<string,vector<string>>mp;

        for(string str:strs){
            string sorted_string=str;
            sort(sorted_string.begin(),sorted_string.end());
            mp[sorted_string].push_back(str);
        }

        for(auto pair:mp){
            ans.push_back(pair.second);
        }
        return ans;
    }
};