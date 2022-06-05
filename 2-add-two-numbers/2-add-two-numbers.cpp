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
        ListNode* ans = new ListNode();
        ListNode *fans=ans;
        int rem=0;
        while(l1 and l2) {
            int sum=l1->val+l2->val+rem;
            rem=sum/10;
            sum%=10;
            l1->val=sum;
            l2->val=sum;
            ans->next=l1;
            ans=ans->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1) {
            int sum=l1->val+rem;
            rem=sum/10;
            sum%=10;
            l1->val=sum;
            ans->next=l1;
            ans=ans->next;
            l1=l1->next;
        }
        while(l2) {
            int sum=l2->val+rem;
            rem=sum/10;
            sum%=10;
            l2->val=sum;
            ans->next=l2;
            ans=ans->next;
            l2=l2->next;
        }
        if(rem) {
            ListNode *remainder = new ListNode(rem);
            ans->next=remainder;
        }
        return fans->next;
    }
};