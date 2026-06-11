/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//  //// BRUTE //// //
// We will move through one of the LL and store each node in map
// Then while traversing through the second one check if it already exists in the map
// Return that node if Yes else NULL

// //// BETTER //// //
// We will make ensure that they both are at same point then start comapring lineraly
class Solution {
public:

    ListNode* intersection(ListNode *n1, ListNode *n2, int d){
        while(d){
            d--;
            n2 = n2->next;
        }

        while(n2 != n1){
            n1 = n1->next;
            n2 = n2->next;    
        }
        return n1;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cntA = 0, cntB = 0;
        ListNode* n1 = headA; 
        ListNode* n2 = headB;

        // Count the number of nodes in each
        while(n1 != NULL){
            cntA++;
            n1 = n1->next;
        }
        while(n2 != NULL){
            cntB++;
            n2 = n2->next;
        }

        // int d = cntB-cntA
        if(cntA < cntB){
            return intersection(headA, headB, cntB-cntA);
        }else
            return intersection(headB, headA, cntA-cntB);

    }
};