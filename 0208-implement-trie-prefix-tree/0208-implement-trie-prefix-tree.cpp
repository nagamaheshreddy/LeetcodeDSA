class Node{
    public:
        unordered_map<char,Node*>mp;
        bool isEnd;

        Node(){
            isEnd=false;
        }
};
class Trie {
public:
    Node* root;

    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* curr=root;
        for(char ch:word){
            if(curr->mp.find(ch)==curr->mp.end()){
                curr->mp[ch]=new Node();
            }
            curr=curr->mp[ch];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        Node* curr=root;
        for(char ch:word){
            if(curr->mp.find(ch)==curr->mp.end()){
                return false;
            }
            curr=curr->mp[ch];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string word) {
        Node* curr=root;
        for(char ch:word){
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