// recursion.cpp
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
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (head == nullptr || k <= 1)
      return head;
    ListNode *cur = head;
    int count = 0;
    for (; count < k && cur != nullptr; ++count)
      cur = cur->next;
    if (count == k) {
      ListNode *tail = reverseKGroup(cur, k);
      ListNode *pre = tail, *now = head, *next;
      while (now != cur) {
        next = now->next;
        now->next = pre;
        pre = now;
        now = next;
      }
      head = pre;
    }
    return head;
  }
};
