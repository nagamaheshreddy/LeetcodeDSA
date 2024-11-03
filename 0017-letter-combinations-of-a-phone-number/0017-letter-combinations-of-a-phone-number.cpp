class Solution {
public:

    void dfs(int ind,string digits,string &currStr,vector<string>&ans,unordered_map<char,string>&mp){
        if(currStr.size()==digits.size()){
            ans.push_back(currStr);
            return;
        }

        for(char ch:mp[digits[ind]]){
            currStr+=ch;
            dfs(ind+1,digits,currStr,ans,mp);
            currStr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};

        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";

        vector<string>ans;
        string currStr="";
        dfs(0,digits,currStr,ans,mp);

        return ans;
    }
};