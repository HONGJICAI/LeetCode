// solution.cpp
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
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == NULL || head->next == NULL)
      return head;
    ListNode *p = head, *tail;
    int len = 0;
    while (p != NULL) {
      len++;
      p = p->next;
    }
    p = head;
    for (int i = 0; i < len - 1; i++)
      p = p->next;
    tail = p;
    k %= len;
    if (k == 0)
      return head;
    p = head;
    for (int i = 0; i < len - 1 - k; i++)
      p = p->next;
    ListNode *newhead = p->next;
    tail->next = head;
    p->next = NULL;
    return newhead;
  }
};
