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
        ListNode* fast = head;

        for(int i = 0; i < n; i++){
            fast = fast->next;
        }

        if(fast == NULL){
            ListNode* newHead = head->next;
            delete(head);
            return newHead;
        }
        
        ListNode* slow = head;
        while(fast->next != NULL){
            fast = fast->next;
            //After the loop ends THe slow will point exactly 
            // at the prev of temp that is the node to be deleted
            slow = slow->next; 
        }

        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete(delNode);
        return head;
    }
};




// // //// BRUTE FORCE (TC:O(2Len), SC:O(1)) //// //
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int count = 0;
//         ListNode* temp = head;
//         // Keep count of the index till which we have to go
//         while(temp != NULL){
//             count++;
//             temp = temp->next;
//         }

//         // if n comes till the curr head then just return head->next;
//         if(count == n){
//             ListNode* newHead = head->next;
//             delete(head);
//             return newHead;
//         }

//         int res = count - n;
//         temp = head;

//         // Loop and keep moving to temp->next until u have exhausted res
//         while(temp != NULL){
//             res--;
//             if(res == 0)break;

//             temp = temp->next;
//         }

//         // Now we are exactly at the node from where we have to break the connection
//         ListNode* delNode = temp->next; //Node that needs to deleted
//         temp->next = temp->next->next;  // Rewiring the new connection

//         // Free memory(use delete instead of free(c) as C++ uses new to allocate memory insted of malloc(C) )
//         delete(delNode);               
//         return head;
//     }
// };