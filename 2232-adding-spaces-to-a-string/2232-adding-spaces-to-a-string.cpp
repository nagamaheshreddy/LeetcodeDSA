class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        set<int>st;
        for(int space:spaces)st.insert(space);

        string ans;
        int i=0;

        while(i<s.size()){
            if(st.contains(i)){
                ans+=" ";
                st.erase(i);
            }else{
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
};