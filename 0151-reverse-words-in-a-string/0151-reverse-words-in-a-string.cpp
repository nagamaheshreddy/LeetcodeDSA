class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string ans;
        vector<string>v;

        while(ss>>word){
            v.push_back(word);  
        }
        reverse(v.begin(),v.end());

        for(auto str:v){
            ans+=str;
            ans+=" ";
        }
        ans.pop_back();

        return ans;
    }
};