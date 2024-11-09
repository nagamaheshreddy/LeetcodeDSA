class Solution {
public:
    string reverseWords(string s) {
        string res;

        stringstream ss(s);
        string word;

        vector<string>ans;

        while(ss>>word){
            ans.push_back(word);
        }
        reverse(ans.begin(),ans.end());

        for(string str:ans){
            res.append(str);
            res+=" ";
        }
        res.pop_back();

        return res;
    }
};