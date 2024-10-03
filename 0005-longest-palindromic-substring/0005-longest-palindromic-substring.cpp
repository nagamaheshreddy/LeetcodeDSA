class Solution {
public:
    bool isPalindrome(int start,int end,string &s){

        while(start<end){
            if(s[start]!=s[end])return false;
            start++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        string ans;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s) && j-i+1>ans.size()){
                    ans=s.substr(i,j-i+1);
                }
            }
        }
        return ans;
    }
};