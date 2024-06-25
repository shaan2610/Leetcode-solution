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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
//         If length of LL is lesser than k
        ListNode *temp = head;
        int cnt = k;
        while(temp and cnt) {
            temp = temp -> next;
            cnt--;
        }
        if(cnt > 0) {
            return head;
        }
        
//         If k = 1, then LL will remain same
        if(k == 1) {
            return head;
        }
        
//          We will reverse the first k elements of the LL
        ListNode *curr = head, *prev = NULL, *forward;
        cnt = 0;
        while(cnt < k) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            cnt++;
        }
        
        head -> next = reverseKGroup(curr, k);
        return prev;
    }
};