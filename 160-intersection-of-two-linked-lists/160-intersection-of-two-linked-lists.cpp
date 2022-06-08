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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        auto calcLen = [&] (ListNode *a) {
            int ans=0;
            while(a) {
                ans++;
                a=a->next;
            }
            return ans;
        };
        
        int lengthA=calcLen(headA),lengthB=calcLen(headB);
        int diff=abs(lengthA-lengthB);
        if(lengthA>lengthB) {
            while(diff--) {
                headA=headA->next;
            }
        }
        else if(lengthB>lengthA) {
            while(diff--) {
                headB=headB->next;
            }
        }
        while(headA!=headB) {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};