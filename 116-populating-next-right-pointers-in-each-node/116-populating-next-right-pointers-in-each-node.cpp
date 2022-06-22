/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(not root) {
            return NULL;
        }
        Node* start=root;
        Node* prev=NULL;
        Node* nextLev=NULL;    
        while(start) {
            if(start->left) {
                if(not prev) {
                    prev=start->left;
                    nextLev=start->left;
                }
                else {
                    prev->next=start->left;
                    prev=start->left;
                }
            }
            if(start->right) {
                if(not prev) {
                    prev=start->right;
                    nextLev=start->right;
                }
                else {
                    prev->next=start->right;
                    prev=start->right;
                }
            }
            if(start->next) {
                start=start->next;
            }
            else {
                start=nextLev;
                prev=NULL;
                nextLev=NULL;
            }
        }
        return root;
    }
};