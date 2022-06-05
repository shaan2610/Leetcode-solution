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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ext=new ListNode(0);
        ext->next=head;
        ListNode *ptr1=ext,*ptr2=ext;
        n++;
        while(ptr2) {
            while(n-->0) {
                ptr2=ptr2->next;
            }
            if(ptr2) {
                ptr2=ptr2->next;
                ptr1=ptr1->next;
            }
        }
        if(ptr1->next) {
            ptr1->next=ptr1->next->next;
        }
        return ext->next;
    }
};