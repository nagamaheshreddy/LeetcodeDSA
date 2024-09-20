class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        string sorted_str;

        for(string str:strs){
            sorted_str=str;
            sort(sorted_str.begin(),sorted_str.end());
            mp[sorted_str].push_back(str);
        }

        vector<vector<string>>ans;
        for(auto pair:mp){
            ans.push_back(pair.second);
        }
        return ans;
    }
};