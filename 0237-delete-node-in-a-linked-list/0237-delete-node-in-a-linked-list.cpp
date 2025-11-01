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
    void deleteNode(ListNode* node) {
        ListNode *prev = NULL;
        while(node->next!=NULL && node!=NULL){
            node->val= node->next->val; // Assign next value to the current node
            prev = node; // mainataining a prev node

            node = node->next;  // Point the current node to the next for moving ahead 
        }

        // In the end point the prev->next to NULL to break the connection 
        // we will have node as the last val which we should delete 
        prev->next=NULL;
        delete node;
    }
};