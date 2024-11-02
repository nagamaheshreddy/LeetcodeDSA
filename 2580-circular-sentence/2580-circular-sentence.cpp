class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n=sentence.size();

        char first=sentence[0];
        char last=sentence[n-1];

        if(first!=last)return false;

        vector<string>words;

        stringstream ss(sentence);
        string word;

        while(ss>>word){
            words.push_back(word);
        }

        char prev=sentence[0];
        for(string word:words){
            if(word[0]!=prev)return false;
            prev=word[word.size()-1];
        }
        return true;
    }
};