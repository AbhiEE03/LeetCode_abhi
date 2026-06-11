// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */


// //  //// BRUTE //// //
// // We will move through one of the LL and store each node in map
// // Then while traversing through the second one check if it already exists in the map
// // Return that node if Yes else NULL

// // //// BETTER //// //
// // TC : O(n1)+O(n2)+O(n2-n1)+O(n1) , SC : O(1)
// // We will make ensure that they both are at same point then start comapring lineraly
// class Solution {
// public:

//     ListNode* intersection(ListNode *headA, ListNode *headB, int d){
//         while(d){
//             d--;
//             headB = headB->next;
//         }

//         while(headB != headA){
//             headA = headA->next;
//             headB = headB->next;    
//         }
//         return headA;
//     }

//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         int cntA = 0, cntB = 0;
//         ListNode* n1 = headA; 
//         ListNode* n2 = headB;

//         // Count the number of nodes in each
//         while(n1 != NULL){
//             cntA++;
//             n1 = n1->next;
//         }
//         while(n2 != NULL){
//             cntB++;
//             n2 = n2->next;
//         }

//         if(cntA < cntB){
//             return intersection(headA, headB, cntB-cntA);
//         }else
//             return intersection(headB, headA, cntA-cntB);

//     }
// };




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// //// OPTIMAL //// //
// Keep moving 2 pointers one for each LL simultaneously 
// As any of them reaches NULL assign it the head of other
// Meanwhile if they are equal at any pt, just return

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;

        ListNode* n1 = headA;
        ListNode* n2 = headB;

        while(n1 != n2){
            n1 = n1->next;
            n2 = n2->next;

            if(n1 == n2) return n1;

            if(n1 == NULL) n1 = headB;
            if(n2 == NULL) n2 = headA;
        }
        return n2;
    }
};



