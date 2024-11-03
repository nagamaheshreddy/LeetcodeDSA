class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char,vector<string>>mp;
        vector<string>ans;
        if(digits.size()==0)return ans;
        
        mp['2']={"a","b","c"};
        mp['3']={"d","e","f"};
        mp['4']={"g","h","i"};
        mp['5']={"j","k","l"};
        mp['6']={"m","n","o"};
        mp['7']={"p","q","r","s"};
        mp['8']={"t","u","v"};
        mp['9']={"w","x","y","z"};
        
        vector<string>prev=mp[digits[0]];
        
        for(int i=1;i<digits.size();i++){
            vector<string>curr=mp[digits[i]];
            vector<string>ans;
            
            for(int j=0;j<prev.size();j++){
                for(int k=0;k<curr.size();k++){
                    ans.push_back(prev[j]+curr[k]);
                }
            }
            prev=ans;
        }
        return prev;
    }
};