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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());

        while(head!=NULL && st.find(head->val)!= st.end()){
            // ListNode *temp = head;
            head = head->next;
            // delete(temp);
        }

        ListNode *curr= head;
        while(curr!=NULL && curr->next!=NULL){
            if(st.find(curr->next->val) != st.end()){
                // ListNode* temp = curr->next;
                curr->next = curr->next->next;
                // delete(temp);
            }else
                curr=curr->next;

        }
        return head;
    }
};

// We don't need to delete the nodes manually beacuse leetcode does it on its own 
// and if we are doing it in our code then leetcode will try to delete it again 
// and we will get runtime error.

// We are handling the head first and then moving to curr-> next.
// Keep moving the current untill u hit null and keep breaking the linkage if curr->next is in the set