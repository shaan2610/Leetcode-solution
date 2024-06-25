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
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* ptr1 = dummy;
        ListNode* ptr2 = dummy;
        int gap = n + 1;
        while(gap-- and ptr2) {
            ptr2 = ptr2 -> next;
        }
        while(ptr1 and ptr2) {
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
//         ptr1 will be at the previous node of the node which we want to delete
        ptr1 -> next = ptr1 -> next -> next;
        return dummy -> next;
    }
};