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
    
    ListNode* reverseLinkedList(ListNode* a) {
        if(a->next==NULL or a==NULL) {
            return a;
        }
        ListNode *temp=a,*nxt=a->next;
        a->next=NULL;
        while(nxt) {
            ListNode* next=nxt->next;
            nxt->next=temp;
            temp=nxt;
            nxt=next;
        }
        return temp;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) {
            return head;
        }
        return reverseLinkedList(head);
    }
};