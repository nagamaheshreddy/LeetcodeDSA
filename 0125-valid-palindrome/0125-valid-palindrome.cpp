class Solution {
public:
    bool isPalindrome(string s) {
       string str;

       for(char ch:s){
        if(isalpha(ch)){
         str+=tolower(ch);
        }else if(isdigit(ch)){
            str+=ch;
        }
       } 
       int n=str.size(),i=0,j=n-1;
       while(i<j){
        if(str[i]!=str[j])return false;
        i++;
        j--;
       }
       return true;
    }
};