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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        // Keep count of the index till which we have to go
        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        // if n comes till the curr head then just return head->next;
        if(count == n){
            ListNode* newHead = head->next;
            delete(head);
            return newHead;
        }

        int res = count - n;
        temp = head;

        // Loop and keep moving to temp->next until u have exhausted res
        while(temp != NULL){
            res--;
            if(res == 0)break;

            temp = temp->next;
        }

        // Now we are exactly at the node from where we have to break the connection
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete(delNode);
        return head;
    }
};