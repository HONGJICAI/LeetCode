// iteration.cpp
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
  ListNode *removeElements(ListNode *head, int val) {
    if (head == NULL)
      return head;
    while (head->val == val) {
      head = head->next;
      if (head == NULL)
        break;
    }
    ListNode *p = head;
    while (p) {
      if (p->next != NULL)
        if (p->next->val == val)
          p->next = p->next->next;
        else
          p = p->next;
      else
        break;
    }
    return head;
  }
};
