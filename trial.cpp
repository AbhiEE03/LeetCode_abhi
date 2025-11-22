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
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    ListNode *node = head;
    int count = 0;
    // 1) Check if there are at least k nodes
    while (node && count < k)
    {
      node = node->next;
      count++;
    }
    if (count < k)
      return head; // fewer than k nodes: no change

    // 2) Reverse first k nodes
    ListNode *prev = nullptr;
    ListNode *curr = head;
    for (int i = 0; i < k; i++)
    {
      ListNode *nxt = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nxt;
    }

    // 3) Recursively process remaining nodes and attach
    head->next = reverseKGroup(curr, k);

    // 4) prev is the new head of this reversed segment
    return prev;
  }
};
