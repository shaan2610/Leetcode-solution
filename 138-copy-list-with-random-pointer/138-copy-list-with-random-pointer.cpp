/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) {
            return NULL;
        }
        Node* dummyHead=head;
        while(dummyHead) {
            Node *temp=new Node(dummyHead->val);
            Node *next=dummyHead->next;
            dummyHead->next=temp;
            temp->next=next;
            dummyHead=next;
            // temp->next=dummyHead->next;
            // dummyHead->next=temp;
            // dummyHead=dummyHead->next->next;
        }
        dummyHead=head;
        while(dummyHead) {
            Node* temp=dummyHead->next;
            if(dummyHead->random) {
                temp->random=dummyHead->random->next;
            }
            else {
                temp->random=NULL;
            }
            dummyHead=temp->next;
        }
        dummyHead=head;
        Node *start=head->next;
        Node *ans=start;
        while(start and dummyHead) {
            // if(dummyHead->next) {
            //     dummyHead->next=dummyHead->next->next;
            //     dummyHead=dummyHead->next;
            // }
            dummyHead->next=dummyHead->next->next;
            if(start->next) {
                start->next=start->next->next;
                start=start->next;
                dummyHead=dummyHead->next;
            }
            else {
                break;
            }
        }
        return ans;
    }
};