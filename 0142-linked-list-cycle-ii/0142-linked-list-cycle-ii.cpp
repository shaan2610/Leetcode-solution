/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) {
            return NULL;
        }
        bool has_cycle = false;
        ListNode *slow = head, *fast = head;
        while(slow and fast and fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) {
                has_cycle = true;
                break;
            }
        }
        
        if(has_cycle == false) {
            return NULL;
        }
        
        slow = head;
        while(slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
};