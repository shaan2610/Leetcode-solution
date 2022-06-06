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
    
    void reverseListNode(ListNode* &l2,int k) {
        ListNode *nxt=l2->next,*temp=l2;
        k--;
        while(k--) {
            ListNode *next=nxt->next;
            nxt->next=temp;
            temp=nxt;
            nxt=next;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1 or head==NULL or head->next==NULL) {
            return head;
        }
        ListNode *l1=new ListNode(0);
        ListNode *temp=head,*ans=l1;
        while(temp) {
            int k1=k;
            ListNode *l3=NULL,*temp1=temp;
            ListNode *ans=l1;
            while(k1-->0 and temp1) {
                l3=temp1;
                temp1=temp1->next;
            }
            if(k1==-1) {
                ListNode *l4=temp1,*l2=temp;
                reverseListNode(l2,k);
                l1->next=l3;
                l2->next=l4;
                l1=l2;
                l2=l4;
            }
            
            temp=temp1;
        }
        return ans->next;
    }
};