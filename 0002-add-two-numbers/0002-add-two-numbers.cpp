/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newHead=new ListNode();
        ListNode* dummy=newHead;
        ListNode* a=l1;
        ListNode* b=l2;

        int carry=0,sum=0,rem=0;
        while(a || b || carry){
            sum=carry;
            if(a) {
                sum+=a->val;
                a=a->next;
            }
            if(b) {
                sum+=b->val;
                b=b->next;
            }
            rem=sum%10;
            carry=sum/10;
            dummy->next=new ListNode(rem);
            dummy=dummy->next;

        }

        return newHead->next;
    }
};