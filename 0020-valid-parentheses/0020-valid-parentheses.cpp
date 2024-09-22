class Solution {
public:
    

    bool isValid(string s) {
        stack<char>st;
        unordered_map<char,char>mp;
        mp[')']='(';
        mp['}']='{';
        mp[']']='[';

        for(char ch:s){
            if(mp.find(ch)==mp.end()){
                st.push(ch);
            }else{
                if(!st.empty() && mp[ch]==st.top()){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};