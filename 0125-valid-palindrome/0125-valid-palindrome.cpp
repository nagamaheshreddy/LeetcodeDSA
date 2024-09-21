class Solution {
public:
    bool isPalindrome(string s) {
       string str="";
        int n=s.size();
        
        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z' || s[i]>='0' and s[i]<='9'){
                str+=s[i];
            }
            else if(s[i]>='A' && s[i]<='Z'){
                char c=tolower(s[i]);
                str+=c;
            }
        }
        int i=0;
        int j=str.size()-1;
        
        while(i<j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};