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
    
    void reverseListNode(ListNode* &start) {
        if(start==NULL or start->next==NULL) {
            return;
        }
        ListNode *nxt=start->next;
        start->next=NULL;
        while(nxt) {
            ListNode *next=nxt->next;
            nxt->next=start;
            start=nxt;
            nxt=next;
        }
    }
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL or head->next==NULL) {
            return true;
        }
        ListNode *slow=head,*fast=head;
        do {
            if(fast->next) {
                fast=fast->next;
            }
            if(fast->next) {
                fast=fast->next;
                slow=slow->next;
            }
        } while(fast->next);
        ListNode *st=slow->next;
        slow->next=fast;
        reverseListNode(st);
        ListNode *ptr1=slow->next;
        while(ptr1) {
            if(ptr1->val!=head->val) {
                return false;
            }
            ptr1=ptr1->next;
            head=head->next;
        }
        return true;
    }
};