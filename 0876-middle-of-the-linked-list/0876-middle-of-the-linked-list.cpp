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
    int length(ListNode* node) {        // To calculate length of the LL
        ListNode* temp = node;
        int len = 0;
        while(temp) {
            len++;
            temp = temp -> next;
        }
        return len;
    }
    
    ListNode* middleNode(ListNode* head) {
        int len = length(head);
        int pos = (len / 2) + 1;
        int moves = pos - 1;
        ListNode* temp = head;
        while(moves--) {
            temp = temp -> next;
        }
        return temp;
    }
};