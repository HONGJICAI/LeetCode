// timeOnSpaceO1.cpp
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
  bool isPalindrome(ListNode *head) {
    if (head == NULL)
      return 1;
    if (head->next == NULL)
      return 1;
    ListNode *p1 = head, *p2 = head;
    while (p2->next != NULL) {
      p2 = p2->next;
      if (p2->next == NULL) {
        break;
      }
      p2 = p2->next;
      p1 = p1->next;
    }
    p2 = reverse(NULL, p1->next);
    p1->next = NULL;
    while (head != NULL && p2 != NULL) {
      if (head->val != p2->val)
        return 0;
      head = head->next;
      p2 = p2->next;
    }
    return 1;
  }
  ListNode *reverse(ListNode *pre, ListNode *now) {
    ListNode *next = now->next;
    now->next = pre;
    if (next == NULL)
      return now;
    return reverse(now, next);
  }
};
