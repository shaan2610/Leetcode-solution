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
    bool hasCycle(ListNode *head) {
        map<ListNode*, bool> mp;
        ListNode* temp = head;
        while(temp) {
            if(mp.find(temp) != mp.end()) { // temp is already there in the map
                return true;
            }
            mp[temp] = true;
            temp = temp -> next;
        }
        return false;
    }
};