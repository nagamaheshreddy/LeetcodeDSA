class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')return true;
        if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U')return true;

        return false;
    }
    string reverseVowels(string s) {

       string vowels;
       for(char ch:s){
        if(isVowel(ch)){
            vowels+=ch;
        }
       } 
       reverse(vowels.begin(),vowels.end());

       int j=0,i=0,n=s.size(),m=vowels.size();
        
       while(i<n && j<m){
         if(isVowel(s[i])){
            s[i]=vowels[j];
            j++;
         }
         i++;
       }

        return s;
    }
};