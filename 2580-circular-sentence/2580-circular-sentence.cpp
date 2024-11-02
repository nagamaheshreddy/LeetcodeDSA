class Solution {
public:
    bool isCircularSentence(string sentence) {

        if(sentence.front()!=sentence.back())return false;

        vector<string>words;

        stringstream ss(sentence);
        string word;

        while(ss>>word){
            words.push_back(word);
        }

        string prev="";

        for(string word:words){
            if(prev!="" && prev.back()!=word.front())return false;
            prev=word;
        }
        return true;
    }
};