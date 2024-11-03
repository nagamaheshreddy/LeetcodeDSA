/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        Node* curr=head;

        while(curr){
           Node* newCurr=new Node(curr->val);
           mp[curr]=newCurr;
           curr=curr->next; 
        }

        curr=head;
        while(curr){
            Node* newCurr=mp[curr];
            newCurr->next=mp[curr->next];
            newCurr->random=mp[curr->random];
            curr=curr->next;
        }

        return mp[head];
    }
};