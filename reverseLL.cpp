#include <iostream>
#include <list>
#include <forward_list>
using namespace std;

// ✅ THIS IS REQUIRED
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *n) : val(x), next(n) {}
};

class Solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = nullptr;
    while (curr != nullptr)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};

int main()
{
  // Example usage (not required on LeetCode)
  ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3)));
  Solution sol;
  head = sol.reverseList(head);

  for (ListNode *p = head; p; p = p->next)
    cout << p->val << " ";
  cout << "\n";
}
