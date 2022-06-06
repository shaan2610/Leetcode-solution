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
    
    int lengthOfListNode(ListNode *head,ListNode* &tail) {
        int ans=0;
        while(head) {
            ans++;
            tail=head;
            head=head->next;
        }
        return ans;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL or head->next==NULL) {
            return head;
        }
        ListNode *tail=head;
        int n=lengthOfListNode(head,tail);
        k%=n;
        if(k==0) {
            return head;
        }
        tail->next=head;
        int cnt=n-k-1;
        ListNode *start=head,*ans=head->next;
        while(cnt--) {
            start=start->next;
            ans=ans->next;
        }
        start->next=NULL;
        return ans;
    }
};