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
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (m == n)
      return head;
    ListNode newhead(0);
    newhead.next = head;
    ListNode *left = &newhead;
    n -= m - 1;
    while (--m)
      left = left->next;
    ListNode *right = left->next;
    ListNode *pre = NULL, *now = right;
    while (n--) {
      ListNode *next = now->next;
      now->next = pre;
      pre = now;
      now = next;
    }
    left->next = pre;
    right->next = now;
    return newhead.next;
  }
};
