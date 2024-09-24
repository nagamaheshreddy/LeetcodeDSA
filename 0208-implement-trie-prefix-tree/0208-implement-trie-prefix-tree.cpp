class TrieNode{
public:
    unordered_map<char,TrieNode*>mp;
    bool isEnd=false;
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr=root;
        
        for(char ch:word){
            if(curr->mp.find(ch)==curr->mp.end()){
                curr->mp[ch]=new TrieNode();
            }
            curr=curr->mp[ch];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* curr=root;
        
        for(char ch:word){
            if(curr->mp.find(ch)==curr->mp.end()){
                return false;
            }
            curr=curr->mp[ch];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr=root;
        
        for(char ch:prefix){
            if(curr->mp.find(ch)==curr->mp.end()){
                return false;
            }
            curr=curr->mp[ch];
        }
       return true; 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */